#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    
    cout << "---" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "---" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);    // menghapus 5
    enqueue(Q, 4); printInfo(Q); // menambah 4
    dequeue(Q); printInfo(Q);    // menghapus 2
    dequeue(Q); printInfo(Q);    // menghapus 7
    
    return 0;
}