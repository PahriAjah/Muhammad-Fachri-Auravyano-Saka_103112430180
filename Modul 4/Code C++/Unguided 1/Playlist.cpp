#include "Playlist.h"

void createList(Playlist &L) {
    L.first = NULL;
}

address alokasi(Lagu laguBaru) {
    address P = new Node;
    P->info = laguBaru;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(Playlist &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(Playlist &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter3(Playlist &L, address P) {
    if (L.first == NULL) {
        cout << "Playlist masih kosong!\n";
        return;
    }

    address Q = L.first;
    int count = 1;
    while (Q != NULL && count < 3) {
        Q = Q->next;
        count++;
    }

    if (Q == NULL) {
        cout << "Jumlah lagu kurang dari 3, ditambahkan di akhir playlist.\n";
        insertLast(L, P);
    } else {
        P->next = Q->next;
        Q->next = P;
    }
}

void deleteByJudul(Playlist &L, string judul) {
    if (L.first == NULL) {
        cout << "Playlist kosong!\n";
        return;
    }

    address P = L.first;
    address prev = NULL;

    while (P != NULL && P->info.judul != judul) {
        prev = P;
        P = P->next;
    }

    if (P == NULL) {
        cout << "Lagu dengan judul '" << judul << "' tidak ditemukan.\n";
    } else {
        if (prev == NULL) {
            L.first = P->next;
        } else {
            prev->next = P->next;
        }
        cout << "Lagu '" << judul << "' berhasil dihapus.\n";
        dealokasi(P);
    }
}

void printPlaylist(Playlist L) {
    if (L.first == NULL) {
        cout << "Playlist kosong.\n";
        return;
    }

    address P = L.first;
    int i = 1;
    cout << "\n=== Daftar Lagu dalam Playlist ===\n";
    while (P != NULL) {
        cout << i << ". Judul: " << P->info.judul << endl;
        cout << "   Penyanyi: " << P->info.penyanyi << endl;
        cout << "   Durasi: " << P->info.durasi << " menit\n";
        cout << "----------------------------------\n";
        P = P->next;
        i++;
    }
}
