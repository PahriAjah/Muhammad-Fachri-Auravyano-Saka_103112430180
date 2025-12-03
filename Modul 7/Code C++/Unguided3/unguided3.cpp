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
// PROSEDUR getInputStream
// Membaca input karakter sampai user menekan ENTER
// ------------------------------------------------------
void getInputStream(Stack &S){
    cout << "Masukkan input : ";

    char c;
    while (true){
        c = cin.get();          // baca 1 karakter

        if (c == '\n')          // jika ENTER → berhenti
            break;

        int angka = c - '0';    // ubah char ke int
        push(S, angka);
    }
}

// ------------------------------------------------------
void printInfo(Stack S){
    cout << "[TOP] ";
    for(int i = S.Top-1; i >= 0; i--){
        cout << S.info[i] << " ";
    }
    cout << endl;
}

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
int main(){
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
