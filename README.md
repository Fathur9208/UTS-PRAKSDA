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

