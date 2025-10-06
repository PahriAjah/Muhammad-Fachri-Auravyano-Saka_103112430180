#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah elemen (N): ";
    cin >> N;

    int *ptr;
    ptr = new int[N];

    cout << "\nMasukkan " << N << " bilangan:\n";
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    int jumlah = 0;
    int maks = *ptr;
    int min = *ptr;

    for (int i = 0; i < N; i++) {
        int nilai = *(ptr + i);
        jumlah = jumlah + nilai;

        if (nilai > maks)
            maks = nilai;
        if (nilai < min)
            min = nilai;
    }

    cout << "\n=== Hasil Perhitungan ===" << endl;
    cout << "Jumlah semua bilangan = " << jumlah << endl;
    cout << "Nilai maksimum = " << maks << endl;
    cout << "Nilai minimum = " << min << endl;

    delete[] ptr;

    return 0;
}
