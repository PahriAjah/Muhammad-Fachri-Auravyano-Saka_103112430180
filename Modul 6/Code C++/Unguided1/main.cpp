#include <iostream>
#include "Doublylist.h"
#include "Doublylist.cpp"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype dataKendaraan;
    address P;

    
    
    dataKendaraan = {"D001", "hitam", 90};
    P = alokasi(dataKendaraan);
    insertLast(L, P);

    
    dataKendaraan = {"D003", "putih", 70};
    P = alokasi(dataKendaraan);
    insertLast(L, P);

    
    std::cout << "masukkan nomor polisi: D001" << std::endl;
    if (findElm(L, "D001") != Nil) {
        std::cout << "nomor polisi sudah terdaftar" << std::endl << std::endl;
    }

    
    dataKendaraan = {"D004", "kuning", 90};
    P = alokasi(dataKendaraan);
    insertLast(L, P);

    
    std::cout << "\nDATA LIST 1" << std::endl;
    printInfo(L);
    std::cout << "------------------------------------" << std::endl;

    
    std::string cariNopol = "D001";
    std::cout << "\nMasukkan Nomor Polisi yang dicari: " << cariNopol << std::endl;
    address ditemukan = findElm(L, cariNopol);
    if (ditemukan != Nil) {
        std::cout << "Data ditemukan:" << std::endl;
        std::cout << "Nomor Polisi: " << ditemukan->info.nopol << std::endl;
        std::cout << "Warna       : " << ditemukan->info.warna << std::endl;
        std::cout << "Tahun       : " << ditemukan->info.thnBuat << std::endl;
    } else {
        std::cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan." << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;

    
    std::string nopolHapus = "D003";
    std::cout << "\nMasukkan Nomor Polisi yang akan dihapus : " << nopolHapus << std::endl;

    address elmHapus = findElm(L, nopolHapus);
    if (elmHapus != Nil) {
        address Pdel; 
        if (elmHapus == L.first) { 
            deleteFirst(L, Pdel);
        } else if (elmHapus == L.last) { 
            deleteLast(L, Pdel);
        } else { 
            address Prec = elmHapus->prev; 
            deleteAfter(L, Prec, Pdel);
        }
        std::cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << std::endl;
    } else {
        std::cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;

    
    std::cout << "\nDATA LIST 1" << std::endl;
    printInfo(L);
    std::cout << "------------------------------------" << std::endl;


    return 0;
}