#ifndef Doublylist_H
#define Doublylist_H

#include <iostream>
#include <string>

#define Nil NULL


struct infotype {
    std::string nopol;
    std::string warna;
    int thnBuat;
};


typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};


struct List {
    address first;
    address last;
};

/** Deklarasi Prosedur dan Fungsi **/

void CreateList(List &L);

address alokasi(infotype x);

void dealokasi(address &P);

void printInfo(List L);

void insertLast(List &L, address P);

address findElm(List L, std::string nopol);

void deleteFirst(List &L, address &P);

void deleteLast(List &L, address &P);

void deleteAfter(List &L, address &Prec, address &P);

#endif