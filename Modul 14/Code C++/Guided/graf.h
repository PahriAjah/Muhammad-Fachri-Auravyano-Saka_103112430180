#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infograf;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* addrNode;
typedef ElmEdge* addrEdge;

struct ElmNode {
    infograf info;
    int visited;
    addrEdge firstEdge;
    addrNode next;
};

struct ElmEdge {
    addrNode node;
    addrEdge next;
};

struct Graph {
    addrNode first;
};

// PRIMITIF GRAPH
void createGraph(Graph &G);
addrNode AllocateNode(infograf X);
addrEdge AllocateEdge(addrNode N);

void InsertNode(Graph &G, infograf X);
addrNode FindNode(Graph G, infograf X);

void ConnectNode(Graph &G, infograf A, infograf B);

void PrintGraph(Graph G);

// Traversal
void ResetVisited(Graph &G);
void PrintDFS(Graph G, addrNode N);
void PrintBFS(Graph G, addrNode N);

#endif