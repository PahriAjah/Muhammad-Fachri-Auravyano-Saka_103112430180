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
    int nextTail = (Q.tail + 1) % MAX_SIZE;
    return (nextTail == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh! Data " << x << " gagal masuk." << endl;
    } else {
        
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } 
        
        else if (Q.tail == MAX_SIZE - 1) {
            Q.tail = 0; 
        } 
        
        else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
    
    infotype dataKeluar = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }
    
    else if (Q.head == MAX_SIZE - 1) {
        Q.head = 0;
    }
    
    else {
        Q.head++;
    }
    
    return dataKeluar;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "H: " << Q.head << " - T: " << Q.tail << " \t | Queue Kosong" << endl;
    } else {
        cout << "H: " << Q.head << " - T: " << Q.tail << " \t | ";
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            
            if (i == Q.tail) break; 
            
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        }
        cout << endl;
    }
}