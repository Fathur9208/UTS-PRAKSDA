# UTS-PRAKSDA
UTS PRAKSDA 

# Arithmetic Expression Converter

Program ini mengonversi ekspresi aritmatika antara notasi Infix, Postfix, dan Prefix menggunakan bahasa C.

## Deskripsi
Program ini menyediakan 6 jenis konversi:
1. Infix → Postfix
2. Postfix → Infix
3. Infix → Prefix
4. Prefix → Infix
5. Prefix → Postfix
6. Postfix → Prefix

Menggunakan dua jenis *stack*:
- `CharStack` untuk menyimpan operator
- `StringStack` untuk menyimpan operand dan ekspresi sementara

## Fitur
- Validasi operator: `+`, `-`, `*`, `/`
- Penanganan tanda kurung `()`
- Prioritas operator (precedence)
- Konversi dua arah untuk semua notasi

## Requirements
- Kompiler C (contoh: gcc)
- Library standar C: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<ctype.h>`

## Cara Menggunakan
1. Kompilasi program:
   gcc parsing_expression.c -o parsing_expression
2. Jalankan program:
   ./parsing_expression
3. Pilih menu konversi (1-6)
4. Masukkan ekspresi sesuai jenis konversi yang dipilih
5. Program akan menampilkan hasil konversi

## Contoh input
- Pilih konversi: 1
- Masukkan ekspresi: (A+B)*C-D
- Hasil: AB+C*D-
- 
## Detail Konversi
1. Infix → Postfix
Menggunakan algoritma Shunting Yard:

Handle operator precedence

Penanganan tanda kurung

Output tanpa parentheses

2. Postfix → Infix
Bangun ekspresi dengan format (operand1 operator operand2)

Tambahkan parentheses otomatis

3. Infix → Prefix
Reverse string infix

Tukar tanda kurung

Konversi ke postfix

Reverse hasil

4. Prefix → Infix
Reverse string prefix

Bangun ekspresi dari kanan ke kiri

Tambahkan parentheses

5. Prefix ↔ Postfix
Menggunakan kombinasi:

Double reversal untuk mempertahankan urutan operand

Stack string untuk konstruksi ekspresi

6. Postfix → Prefix
Operator gabung 2 operand sebelumnya

Format: operator operand1 operand2



## Contoh Konversi
Jenis Input Output
1. Infix→Postfix A+B*C ABC*+
2. Postfix→Infix AB+C* (A+B)*C
3. Infix→Prefix (A+B)*C *+ABC
4. Prefix→Infix *+AB-C ((A+B)*(-C))
5. Prefix→Postfix +*AB-C AB*C-+
6. Postfix→Prefix AB*C+ +*ABC
