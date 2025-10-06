#include <iostream>
using namespace std;
int main() {
    int x, y;
    int *px;
    x = 87;
    px = &x;
    px = &x;
    y = *px;

    // Menampilkan Informasi
    cout << "alamat x       = " << &x << endl;
    cout << "isi px         = " << px << endl;
    cout << "isi x          = " << x << endl;
    cout << "nilai *px      = " << *px << endl;
    cout << "nilai y        = " << y << endl;

    return 0;
}