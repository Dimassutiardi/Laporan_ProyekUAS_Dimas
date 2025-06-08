#include <stdio.h>

#define N 9  // Jumlah titik data (harus ganjil untuk Simpson's 1/3)

// Data waktu dan kecepatan
double waktu[N]    = {0, 1, 2, 3, 4, 5, 6, 7, 8};          // dalam detik
double kecepatan[N] = {0, 5, 10, 15, 20, 25, 28, 30, 32};  // dalam m/s

double simpson_integrasi(double x[], double y[], int n) {
    if (n % 2 == 0) {
        printf("Jumlah titik data harus ganjil untuk Simpson's 1/3 Rule.\n");
        return -1;
    }

    double h = x[1] - x[0]; // Asumsikan selang waktu seragam
    double integral = y[0] + y[n - 1];

    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0)
            integral += 2 * y[i];
        else
            integral += 4 * y[i];
    }

    integral *= h / 3.0;
    return integral;
}

int main() {
    double jarak = simpson_integrasi(waktu, kecepatan, N);
    if (jarak >= 0) {
        printf("Jarak total yang ditempuh mobil: %.4f meter\n", jarak);
    }
    return 0;
}
