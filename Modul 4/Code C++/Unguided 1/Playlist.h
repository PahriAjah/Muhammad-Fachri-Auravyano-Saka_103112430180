#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
};

typedef struct Node *address;

struct Node {
    Lagu info;
    address next;
};

struct Playlist {
    address first;
};

// Prototipe fungsi
void createList(Playlist &L);
address alokasi(Lagu laguBaru);
void dealokasi(address P);

void insertFirst(Playlist &L, address P);
void insertLast(Playlist &L, address P);
void insertAfter3(Playlist &L, address P);
void deleteByJudul(Playlist &L, string judul);
void printPlaylist(Playlist L);

#endif
