#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh! (Tail sudah di ujung)" << endl;
    } else {
        
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            
            Q.tail++;
        }
        
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong! Tidak bisa ambil data." << endl;
        return -1; 
    }
    
    infotype dataKeluar = Q.info[Q.head];
    
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++; 
    }
    
    return dataKeluar;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "H: " << Q.head << " - T: " << Q.tail << " \t | Queue Kosong" << endl;
    } else {
        cout << "H: " << Q.head << " - T: " << Q.tail << " \t | ";
        
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}