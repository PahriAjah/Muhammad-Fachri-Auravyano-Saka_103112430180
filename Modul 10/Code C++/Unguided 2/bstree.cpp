#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x); 
        } else if (x > root->info) {
            insertNode(root->right, x); 
        }
        
    }
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungNode(address root) {
    if (root == Nil) {
        return 0; 
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil) {
        return 0; 
    }
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int current) {
    if (root == Nil) {
        return current; 
    }
        
    int kiri = hitungKedalaman(root->left, current + 1);
    int kanan = hitungKedalaman(root->right, current + 1);
    
    if (kiri > kanan) {
        return kiri;
    } else {
        return kanan;
    }
}