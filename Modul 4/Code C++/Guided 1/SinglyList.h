#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#define Nil NULL
#include <iostream>
using namespace std;

/*deklarasi record dan struktur data list*/
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};
struct list{
    address first;
};

void createList(list &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void printInfo(list L);

#endif // SINGLYLIST_H_INCLUDED