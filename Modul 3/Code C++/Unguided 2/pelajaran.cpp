#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string nama, string kode) {
    pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(pelajaran p) {
    cout << "nama pelajaran : " << p.namaMapel << endl;
    cout << "nilai : " << p.kodeMapel << endl;
}
