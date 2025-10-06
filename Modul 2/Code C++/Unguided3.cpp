#include <iostream>
using namespace std;

float hitungRata(int nilai[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total = total + nilai[i];
    }
    return total / n;
}

void cariNilai(int nilai[], int n, int &maks, int &min) {
    maks = nilai[0];
    min = nilai[0];
    for (int i = 1; i < n; i++) {
        if (nilai[i] > maks)
            maks = nilai[i];
        if (nilai[i] < min)
            min = nilai[i];
    }
}

int main() {
    int N;
    cout << "Masukkan jumlah siswa: ";
    cin >> N;

    int nilai[N];
    for (int i = 0; i < N; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    float rata = hitungRata(nilai, N);

    int tertinggi, terendah;
    cariNilai(nilai, N, tertinggi, terendah);

    cout << "\n=== Hasil Perhitungan ===" << endl;
    cout << "Rata-rata kelas  : " << rata << endl;
    cout << "Nilai tertinggi  : " << tertinggi << endl;
    cout << "Nilai terendah   : " << terendah << endl;

    return 0;
}
