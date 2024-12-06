#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define INF 999

typedef int LabelAdjMat[MAX][MAX];
typedef struct{
    int u, v;
    int weight;
}edgeType;

#define MAX_SIZE 20
typedef struct{
    edgeType edges[MAX_SIZE];
    int lastNdx;
}minHeapOrList;

typedef struct{
    minHeapOrList eList;
    int cost;
}Kruskal, Prim;

void initMinHeap(minHeapOrList*);   //helper
void createMinHeap(minHeapOrList*, LabelAdjMat);    //preliminary
void insertMinHeap(int weight, int u, int v, minHeapOrList *);  //helper: inserts element in LabelAdjMat as newly created edgeType and heapify.
edgeType deleteMinHeap(minHeapOrList *);    //preliminary
void heapifySubtree(int index, minHeapOrList *);    //helper: given the index, heapifies its subtrees.

// void heapifySubtree(int index, minHeapOrList * heap){
//     int LC = index * 2 + 1;
//     int RC = LC + 1;

// }