#include "graf.h"
#include <queue>
#include <stack>

void createGraph(Graph &G) {
    G.first = NULL;
}

addrNode AllocateNode(infograf X) {
    addrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

addrEdge AllocateEdge(addrNode N) {
    addrEdge P = new ElmEdge;
    P->node = N;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infograf X) {
    addrNode P = AllocateNode(X);
    P->next = G.first;
    G.first = P;
}

addrNode FindNode(Graph G, infograf X) {
    addrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infograf A, infograf B) {
    addrNode N1 = FindNode(G, A);
    addrNode N2 = FindNode(G, B);

    if (N1 == NULL || N2 == NULL) {
        cout << "Node tidak ditemukan\n";
        return;
    }

    // Buat Edge daro N1 ke N2
    addrEdge E1 = AllocateEdge(N2);
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    // Karena undirected -> buat Edge balik
    addrEdge E2 = AllocateEdge(N1);
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    addrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        addrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G) {
    addrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph G, addrNode N) {
    if (N == NULL)
    return;
    N->visited = 1;
    cout << N->info << " ";

    addrEdge E = N->firstEdge;
    while (E != NULL)
    {
        if (E->node->visited == 0) {
            PrintDFS(G, E->node);
        }
        E = E->next;
    }
}

void PrintBFS(Graph G, addrNode N) {
    if (N == NULL)
        return;

    queue<addrNode> Q;
    Q.push(N);

    while (!Q.empty()) {
        addrNode curr = Q.front();
        Q.pop();
        if (curr->visited == 0) {
            curr->visited = 1;
            cout << curr->info << " ";

            addrEdge E = curr->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}