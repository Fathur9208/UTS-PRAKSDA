#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definisi struktur data untuk stack karakter
typedef struct CharStackNode {
    char data;
    struct CharStackNode *next;
} CharStackNode;

typedef struct {
    CharStackNode *top;
} CharStack;

CharStack* createCharStack() {
    CharStack *stack = (CharStack*)malloc(sizeof(CharStack));
    stack->top = NULL;
    return stack;
}

void pushChar(CharStack *stack, char data) {
    CharStackNode *newNode = (CharStackNode*)malloc(sizeof(CharStackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char popChar(CharStack *stack) {
    if (stack->top == NULL) return '\0';
    CharStackNode *temp = stack->top;
    char data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isEmptyChar(CharStack *stack) {
    return stack->top == NULL;
}

char topChar(CharStack *stack) {
    if (isEmptyChar(stack)) return '\0';
    return stack->top->data;
}

// Definisi struktur data untuk stack string
typedef struct StringStackNode {
    char *data;
    struct StringStackNode *next;
} StringStackNode;

typedef struct {
    StringStackNode *top;
} StringStack;

StringStack* createStringStack() {
    StringStack *stack = (StringStack*)malloc(sizeof(StringStack));
    stack->top = NULL;
    return stack;
}

void pushString(StringStack *stack, const char *data) {
    StringStackNode *newNode = (StringStackNode*)malloc(sizeof(StringStackNode));
    newNode->data = strdup(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

char* popString(StringStack *stack) {
    if (stack->top == NULL) return NULL;
    StringStackNode *temp = stack->top;
    char *data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isEmptyString(StringStack *stack) {
    return stack->top == NULL;
}

void freeStringStack(StringStack *stack) {
    while (!isEmptyString(stack)) {
        char *data = popString(stack);
        free(data);
    }
    free(stack);
}

// Fungsi bantu
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPrecedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

char* reverseString(const char *str) {
    int len = strlen(str);
    char *reversed = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

void swapParentheses(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

// Fungsi konversi
char* infixToPostfix(const char *infix) {
    CharStack *stack = createCharStack();
    int len = strlen(infix);
    char *postfix = (char*)malloc(2 * len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            pushChar(stack, c);
        } else if (c == ')') {
            while (!isEmptyChar(stack) && topChar(stack) != '(') {
                postfix[j++] = popChar(stack);
            }
            popChar(stack);
        } else if (isOperator(c)) {
            while (!isEmptyChar(stack) && getPrecedence(topChar(stack)) >= getPrecedence(c)) {
                postfix[j++] = popChar(stack);
            }
            pushChar(stack, c);
        }
    }
    while (!isEmptyChar(stack)) {
        postfix[j++] = popChar(stack);
    }
    postfix[j] = '\0';
    free(stack);
    return postfix;
}

char* postfixToInfix(const char *postfix) {
    StringStack *stack = createStringStack();
    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            pushString(stack, operand);
        } else if (isOperator(c)) {
            char *op2 = popString(stack);
            char *op1 = popString(stack);
            char *newExpr = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(newExpr, "(%s%c%s)", op1, c, op2);
            pushString(stack, newExpr);
            free(op1);
            free(op2);
            free(newExpr);
        }
    }
    char *result = popString(stack);
    freeStringStack(stack);
    return result;
}

char* infixToPrefix(const char *infix) {
    char *reversed = reverseString(infix);
    swapParentheses(reversed);
    char *postfix = infixToPostfix(reversed);
    free(reversed);
    char *prefix = reverseString(postfix);
    free(postfix);
    return prefix;
}

char* prefixToInfix(const char *prefix) {
    char *reversed = reverseString(prefix);
    StringStack *stack = createStringStack();
    int len = strlen(reversed);

    for (int i = 0; i < len; i++) {
        char c = reversed[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            pushString(stack, operand);
        } else if (isOperator(c)) {
            char *op1 = popString(stack);
            char *op2 = popString(stack);
            char *newExpr = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(newExpr, "(%s%c%s)", op1, c, op2);
            pushString(stack, newExpr);
            free(op1);
            free(op2);
            free(newExpr);
        }
    }
    free(reversed);
    char *result = popString(stack);
    freeStringStack(stack);
    return result;
}

char* prefixToPostfix(const char *prefix) {
    char *reversed = reverseString(prefix);
    StringStack *stack = createStringStack();
    int len = strlen(reversed);

    for (int i = 0; i < len; i++) {
        char c = reversed[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            pushString(stack, operand);
        } else if (isOperator(c)) {
            char *op1 = popString(stack);
            char *op2 = popString(stack);
            char *newExpr = (char*)malloc(strlen(op1) + strlen(op2) + 2);
            sprintf(newExpr, "%s%s%c", op1, op2, c);
            pushString(stack, newExpr);
            free(op1);
            free(op2);
            free(newExpr);
        }
    }
    free(reversed);
    char *result = popString(stack);
    freeStringStack(stack);
    return result;
}

char* postfixToPrefix(const char *postfix) {
    StringStack *stack = createStringStack();
    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            pushString(stack, operand);
        } else if (isOperator(c)) {
            char *op2 = popString(stack);
            char *op1 = popString(stack);
            char *newExpr = (char*)malloc(strlen(op1) + strlen(op2) + 2);
            sprintf(newExpr, "%c%s%s", c, op1, op2);
            pushString(stack, newExpr);
            free(op1);
            free(op2);
            free(newExpr);
        }
    }
    char *result = popString(stack);
    freeStringStack(stack);
    return result;
}

int main() {
    int choice;
    char expression[100];
    char *result;

    printf("Pilih konversi:\n");
    printf("1. Infix ke Postfix\n2. Postfix ke Infix\n3. Infix ke Prefix\n");
    printf("4. Prefix ke Infix\n5. Prefix ke Postfix\n6. Postfix ke Prefix\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &choice);
    getchar();

    printf("Masukkan ekspresi: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    switch (choice) {
        case 1: result = infixToPostfix(expression); break;
        case 2: result = postfixToInfix(expression); break;
        case 3: result = infixToPrefix(expression); break;
        case 4: result = prefixToInfix(expression); break;
        case 5: result = prefixToPostfix(expression); break;
        case 6: result = postfixToPrefix(expression); break;
        default: printf("Pilihan tidak valid.\n"); return 1;
    }

    printf("Hasil: %s\n", result);
    free(result);
    return 0;
}
