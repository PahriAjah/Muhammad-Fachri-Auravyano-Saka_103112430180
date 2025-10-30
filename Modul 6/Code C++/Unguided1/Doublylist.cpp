#include "Doublylist.h"

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil; 
}

void printInfo(List L) {
    address P = L.first;
    if (L.first == Nil) {
        std::cout << "List kosong!" << std::endl;
    } else {
        while (P != Nil) {
            std::cout << "Nomor Polisi: " << P->info.nopol << std::endl;
            std::cout << "Warna       : " << P->info.warna << std::endl;
            std::cout << "Tahun       : " << P->info.thnBuat << std::endl;
            std::cout << std::endl;
            P = P->next;
        }
    }
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { 
        L.first = P;
        L.last = P;
    } else { 
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, std::string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil; 
}

void deleteFirst(List &L, address &P) {
    P = L.first; 
    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else { 
        L.first = P->next;
        L.first->prev = Nil;
        P->next = Nil; 
    }
    dealokasi(P); 
}

void deleteLast(List &L, address &P) {
    P = L.last; 
    if (L.first == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else { 
        L.last = P->prev;
        L.last->next = Nil;
        P->prev = Nil; 
    }
    dealokasi(P); 
}

void deleteAfter(List &L, address &Prec, address &P) {
    
    P = Prec->next; 
    if (P == L.last) { 
        deleteLast(L, P); 
    } else { 
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = Nil; 
        P->prev = Nil; 
        dealokasi(P); 
    }
}