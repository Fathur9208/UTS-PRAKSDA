# UTS-PRAKSDA
UTS PRAKSDA 

# Arithmetic Expression Converter

Program ini mengonversi ekspresi aritmatika antara notasi Infix, Postfix, dan Prefix menggunakan struktur data stack dalam bahasa C.

## Deskripsi
Program ini menyediakan 6 jenis konversi:
1. Infix → Postfix
2. Postfix → Infix
3. Infix → Prefix
4. Prefix → Infix
5. Prefix → Postfix
6. Postfix → Prefix

## Menggunakan dua jenis *stack*:
- `CharStack` untuk menyimpan operator
- `StringStack` untuk menyimpan operand dan ekspresi sementara

## Fitur
- Validasi operator: `+`, `-`, `*`, `/`
- Penanganan tanda kurung `()`
- Prioritas operator (precedence)
- Konversi dua arah untuk semua notasi

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
 
## Detail Konversi
1. Infix → Postfix
- Algoritma: Shunting Yard
- Handle prioritas operator
- Keluaran tanpa tanda kurung

2. Postfix → Infix
- Format: (operand1 operator operand2)
- Tanda kurung otomatis ditambahkan

3. Infix → Prefix
- Balikkan string Infix
- Tukar tanda kurung ( ↔ )
- Konversi ke Postfix
- Balikkan hasil

4. Prefix → Infix
- Balikkan string Prefix
- Bangun ekspresi dari kanan ke kiri
- Tambahkan tanda kurung

5. Prefix → Postfix
- Balikkan string Prefix
- Bangun ekspresi Postfix dengan stack

6. Postfix → Prefix
- Algoritma: Push operand ke stack
- Saat menemukan operator:
- Pop 2 operand teratas (op2 lalu op1)
- Gabungkan menjadi operator + op1 + op2
- Push hasil ke stack

## Contoh Konversi
Jenis Input Output
1. Infix→Postfix A+B*C ABC*+
2. Postfix→Infix AB+C* (A+B)*C
3. Infix→Prefix (A+B)*C *+ABC
4. Prefix→Infix *+AB-C ((A+B)*(-C))
5. Prefix→Postfix +*AB-C AB*C-+
6. Postfix→Prefix AB*C+ +*ABC

## Catatan
Asumsi:
- Operand berupa karakter alfanumerik tunggal (misal: A, b, 1)
- Input valid dan tidak mengandung spasi
- Operator yang didukung: +, -, *, /

Batasan:
- Tidak mendukung operator unary (misal: -5)
- Tidak validasi ekspresi tidak lengkap (misal: A+)
