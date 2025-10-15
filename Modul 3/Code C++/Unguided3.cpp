#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp;
    temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int B[3][3] = { {9,8,7}, {6,5,4}, {3,2,1} };
    int *ptr1, *ptr2;
    int x = 10, y = 20;

    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "\nArray B:" << endl;
    tampilArray(B);

    cout << "\nMenukar posisi elemen (baris=1, kolom=2)" << endl;
    tukarPosisi(A, B, 1, 2); // posisi baris ke-1 kolom ke-2

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);
    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    // pointer
    ptr1 = &x;
    ptr2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Setelah tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
