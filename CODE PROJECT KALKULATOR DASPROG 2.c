#include <stdio.h>
#include <string.h>
#include <math.h>

// 1. HUKUM OHM

void kalkulatorOhm() {
    int pilihan;
    double V, I, R;

    printf("--- Kalkulator Hukum Ohm (V = I * R) ---\n");
    printf("Hitung apa?\n1. Tegangan (V)\n2. Arus (I)\n3. Hambatan (R)\nPilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        printf("Masukkan Arus (I): ");
        scanf("%lf", &I);
        printf("Masukkan Hambatan (R): ");
        scanf("%lf", &R);
        V = I * R;
        printf("Tegangan (V) = %.4lf Volt\n", V);

    } else if (pilihan == 2) {
        printf("Masukkan Tegangan (V): ");
        scanf("%lf", &V);
        printf("Masukkan Hambatan (R): ");
        scanf("%lf", &R);
        I = V / R;
        printf("Arus (I) = %.4lf Ampere\n", I);

    } else if (pilihan == 3) {
        printf("Masukkan Tegangan (V): ");
        scanf("%lf", &V);
        printf("Masukkan Arus (I): ");
        scanf("%lf", &I);
        R = V / I;
        printf("Hambatan (R) = %.4lf Ohm\n", R);
    } else {
        printf("Pilihan tidak valid.\n");
    }
    getchar(); getchar();
}

// 2. KALKULATOR DAYA

void kalkulatorDaya() {
    double V, I, P;

    printf("--- Kalkulator Daya Listrik (P = V * I) ---\n");
    printf("Masukkan Tegangan (V): ");
    scanf("%lf", &V);
    printf("Masukkan Arus (I): ");
    scanf("%lf", &I);

    P = V * I;
    printf("Daya (P) = %.4lf Watt\n", P);

    getchar(); getchar();
}

// 3. RESISTOR SERI

void resistorSeri() {
    int n;
    double total = 0, r;

    printf("--- Kalkulator Resistor Seri ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &r);
        total += r;
    }

    printf("Total Hambatan Seri = %.4lf Ohm\n", total);

    getchar(); getchar();
}

// 4. RESISTOR PARALEL

void resistorParalel() {
    int n;
    double r, sum = 0;

    printf("--- Kalkulator Resistor Paralel ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &r);
        sum += 1.0 / r;
    }

    double total = 1.0 / sum;
    printf("Total Hambatan Paralel = %.4lf Ohm\n", total);

    getchar(); getchar();
}

// 5. DESIMAL → BINER / OKTAL / HEX

void desimalKeBasis() {
    long long n;

    printf("--- Konversi dari Desimal ---\n");
    printf("Masukkan bilangan desimal: ");
    scanf("%lld", &n);

    // Konversi manual
    char biner[100], oktal[100], heksa[100];
    int idx = 0;
    long long temp = n;

    // Biner
    idx = 0;
    temp = n;
    while (temp > 0) {
        biner[idx++] = (temp % 2) + '0';
        temp /= 2;
    }
    biner[idx] = '\0';
    strrev(biner);

    // Oktal
    idx = 0;
    temp = n;
    while (temp > 0) {
        oktal[idx++] = (temp % 8) + '0';
        temp /= 8;
    }
    oktal[idx] = '\0';
    strrev(oktal);

    // Heksadesimal
    char hexDigits[] = "0123456789ABCDEF";
    idx = 0;
    temp = n;
    while (temp > 0) {
        heksa[idx++] = hexDigits[temp % 16];
        temp /= 16;
    }
    heksa[idx] = '\0';
    strrev(heksa);

    printf("Biner        : %s\n", biner);
    printf("Oktal        : %s\n", oktal);
    printf("Heksadesimal : %s\n", heksa);

    getchar(); getchar();
}

// 6. BINER → DESIMAL

long long konversiKeDesimal(char *str, int basis) {
    long long hasil = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[len - 1 - i];
        int digit;

        if (c >= '0' && c <= '9') digit = c - '0';
        else digit = (c - 'A') + 10;

        hasil += digit * pow(basis, i);
    }
    return hasil;
}

void binerKeDesimal() {
    char bin[100];
    printf("--- Konversi Biner ke Desimal ---\n");
    printf("Masukkan bilangan biner: ");
    scanf("%s", bin);

    printf("Hasil Desimal: %lld\n", konversiKeDesimal(bin, 2));

    getchar(); getchar();
}

void oktalKeDesimal() {
    char oktal[100];
    printf("--- Konversi Oktal ke Desimal ---\n");
    printf("Masukkan bilangan oktal: ");
    scanf("%s", oktal);

    printf("Hasil Desimal: %lld\n", konversiKeDesimal(oktal, 8));

    getchar(); getchar();
}

void heksaKeDesimal() {
    char hex[100];
    printf("--- Konversi Heksadesimal ke Desimal ---\n");
    printf("Masukkan bilangan heksadesimal: ");
    scanf("%s", hex);

    // Ubah huruf ke kapital
    for (int i = 0; i < strlen(hex); i++) {
        if (hex[i] >= 'a' && hex[i] <= 'z')
            hex[i] -= 32;
    }

    printf("Hasil Desimal: %lld\n", konversiKeDesimal(hex, 16));

    getchar(); getchar();
}

// MENU UTAMA

int main() {
    int pilihan;

    do {
        printf("=================================================\n");
        printf("|                  KALKULATOR                   |\n");
        printf("=================================================\n");
        printf("| --- Verifikasi Rangkaian Elektrik ---        |\n");
        printf("| 1. Kalkulator Hukum Ohm (V = I * R)          |\n");
        printf("| 2. Kalkulator Daya Listrik (P = V * I)       |\n");
        printf("| 3. Kalkulator Resistor Seri                  |\n");
        printf("| 4. Kalkulator Resistor Paralel               |\n");
        printf("|                                               |\n");
        printf("| --- Utilitas Sistem Digital ---              |\n");
        printf("| 5. Desimal -> Biner / Oktal / Heksadesimal   |\n");
        printf("| 6. Biner -> Desimal                          |\n");
        printf("| 7. Oktal -> Desimal                          |\n");
        printf("| 8. Heksadesimal -> Desimal                   |\n");
        printf("|                                               |\n");
        printf("| 9. Keluar                                    |\n");
        printf("-------------------------------------------------\n");

        printf("Masukkan pilihan Anda (1-9): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: kalkulatorOhm(); break;
            case 2: kalkulatorDaya(); break;
            case 3: resistorSeri(); break;
            case 4: resistorParalel(); break;
            case 5: desimalKeBasis(); break;
            case 6: binerKeDesimal(); break;
            case 7: oktalKeDesimal(); break;
            case 8: heksaKeDesimal(); break;
            case 9: printf("Terima kasih telah menggunakan toolkit ini!\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 9);

    return 0;
}
