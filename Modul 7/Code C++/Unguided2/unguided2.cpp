#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int Top;
};

void createStack(Stack &S){
    S.Top = 0;
}

bool isEmpty(Stack S){
    return (S.Top == 0);
}

bool isFull(Stack S){
    return (S.Top == MAX);
}

void push(Stack &S, int x){
    if(!isFull(S)){
        S.info[S.Top] = x;
        S.Top++;
    }
}

int pop(Stack &S){
    if(!isEmpty(S)){
        S.Top--;
        return S.info[S.Top];
    }
    return -1;
}

// ------------------------------------------------------
// PROSEDUR pushAscending
// ------------------------------------------------------
void pushAscending(Stack &S, int x){
    Stack temp;
    createStack(temp);

    // pindahkan semua elemen yang > x ke stack sementara
    while(!isEmpty(S) && S.info[S.Top - 1] > x){
        push(temp, pop(S));
    }

    // masukkan x ke stack utama
    push(S, x);

    // kembalikan elemen temp ke stack utama
    while(!isEmpty(temp)){
        push(S, pop(temp));
    }
}

// ------------------------------------------------------
// CETAK STACK
// ------------------------------------------------------
void printInfo(Stack S){
    cout << "[TOP] ";
    for(int i = S.Top-1; i >= 0; i--){
        cout << S.info[i] << " ";
    }
    cout << endl;
}

// ------------------------------------------------------
// BALIK STACK
// ------------------------------------------------------
void balikStack(Stack &S){
    Stack temp;
    createStack(temp);

    while(!isEmpty(S)){
        push(temp, pop(S));
    }

    S = temp;
}

// ------------------------------------------------------
// MAIN PROGRAM (SESUAI GAMBAR SOAL)
// ------------------------------------------------------
int main(){
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);         // Output seperti gambar

    cout << "balik stack" << endl;

    balikStack(S);
    printInfo(S);

    return 0;
}
