#include "SinglyList.h"

void createList(list &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(list &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(list &L, address P) {
    if (L.first == Nil) {
        //jika list kosong, insertlast sama dengan insertfirst
        insertFirst(L, P);
    } else {
        //jika list tidak kosong, cari elemen terakhir
        address Last = L.first;
        while (Last->next != Nil) {
            Last = Last->next;
        }
        Last->next = P;
    }
}

void printInfo(list L) {
    address P = L.first;
    if (P == Nil) {
        std::cout << "List Kosong!" << std::endl;
    } else {
        while (P != Nil) {
            std::cout << P->info << " ";
            P = P->next;
        }
        std::cout << std::endl;
    }
}