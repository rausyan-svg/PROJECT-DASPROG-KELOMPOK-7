ANGGOTA KELOMPOK :
  1. Rausyan Jaisyu Muhammad (5048251041)
  2. M. Haidar Rosyadi       (5048251038)
  3. Hafez Muhammad Fathan   (5048251070)


**PENJELASAN HUKUM OHM - RESISTOR SERI (Rausyan Jaisyu Muhammad)**

  Bagian awal program membangun fondasi kalkulator listrik berbasis Hukum Ohm, daya listrik, dan rangkaian seri. Secara konseptual, ini merepresentasikan prinsip dasar kelistrikan: hubungan linier antara tegangan, arus, dan hambatan, serta sifat aditif hambatan pada rangkaian seri. Setiap fungsi berdiri mandiri (modular), sehingga main() hanya berperan sebagai pengatur alur, bukan pemroses logika. Pada resistor seri, pendekatan iteratif digunakan karena jumlah resistor bersifat dinamis (tidak tetap), mencerminkan kondisi nyata di lapangan ketika jumlah komponen bisa berubah-ubah.
Sintaks fondasi penting:
void kalkulatorOhm()
double V, I, R;
V = I * R;
I = V / R;
R = V / I;
void kalkulatorDaya()
P = V * I;
void resistorSeri()
double total = 0;
for (int i = 1; i <= n; i++) {
    total += r;
}

**PENJELASAN RESISTOR PARALEL DAN PENGUBAH BILANGAN DESIMAL KE BILANGAN LAIN (M. Haidar Rosyadi)**

 Bagian ini mulai memperlihatkan peningkatan kompleksitas logika. Pada resistor paralel, hambatan total tidak lagi bersifat aditif, melainkan mengikuti hukum kebalikan (reciprocal), sehingga diperlukan pendekatan matematis yang berbeda. Ini menunjukkan bahwa struktur fisik sistem memengaruhi model matematisnya. Selanjutnya, konversi desimal ke basis lain membawa program dari ranah kelistrikan ke ranah sistem digital, dengan algoritma pembagian berulang (repeated division) sebagai inti logika konversi. Proses pembalikan string (strrev) menjadi penting karena hasil digit diperoleh dari posisi paling belakang (LSB ke MSB).
Sintaks fondasi penting:
void resistorParalel()
sum += 1.0 / r;
double total = 1.0 / sum;
while (temp > 0) {
    biner[idx++] = (temp % 2) + '0';
    temp /= 2;
}
strrev(biner);
char hexDigits[] = "0123456789ABCDEF";
heksa[idx++] = hexDigits[temp % 16];

**PENJELASAN DARI BILANGAN LAIN KE DESIMAL DAN FUNGSI UTAMA PROGRAM (Hafez Muhammad Fathan)**

 Bagian terakhir adalah puncak abstraksi program: konversi bilangan berbasis string ke nilai numerik desimal. Di sini, karakter tidak lagi diperlakukan sebagai teks biasa, melainkan sebagai representasi nilai numerik berbobot posisi. Fungsi konversiKeDesimal() menjadi inti karena bersifat generik—satu algoritma dapat digunakan untuk basis 2, 8, maupun 16. Pemanfaatan pow() menunjukkan pendekatan matematis langsung terhadap sistem bilangan berpangkat. Menu utama (main) menyatukan seluruh modul dalam satu sistem interaktif berbasis loop, mencerminkan desain aplikasi terminal yang berkelanjutan hingga pengguna memilih keluar.
Sintaks fondasi penting:
long long konversiKeDesimal(char *str, int basis)
hasil += digit * pow(basis, i);
if (c >= '0' && c <= '9') digit = c - '0';
else digit = (c - 'A') + 10;
do {
    scanf("%d", &pilihan);
    switch (pilihan) { ... }
} while (pilihan != 9);
