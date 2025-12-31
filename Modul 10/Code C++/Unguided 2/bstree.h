#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#define Nil NULL 
using namespace std;

typedef int infotype;
typedef struct Node *address; 

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int current);

#endif