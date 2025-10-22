#include "Playlist.h"
#include <iostream>
#include "Playlist.cpp"

using namespace std;

int main() {
    Playlist L;
    createList(L);

    Lagu lagu1 = {"Hati-Hati di Jalan", "Tulus", 4.2};
    Lagu lagu2 = {"Cinta Luar Biasa", "Andmesh", 3.8};
    Lagu lagu3 = {"Celengan Rindu", "Fiersa Besari", 4.0};
    Lagu lagu4 = {"Laskar Pelangi", "Nidji", 5.0};
    Lagu lagu5 = {"Akad", "Payung Teduh", 4.3};

    insertFirst(L, alokasi(lagu1));
    insertLast(L, alokasi(lagu2));
    insertLast(L, alokasi(lagu3));
    insertAfter3(L, alokasi(lagu4)); // setelah lagu ke-3
    insertLast(L, alokasi(lagu5));

    printPlaylist(L);

    cout << "\nMenghapus lagu dengan judul 'Cinta Luar Biasa'...\n";
    deleteByJudul(L, "Cinta Luar Biasa");

    printPlaylist(L);

    return 0;
}
