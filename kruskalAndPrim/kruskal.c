#include "preliminary.h"

// #define MAX 5
// #define INF 999

// typedef int LabelAdjMat[MAX][MAX];
// typedef struct{
//     int u, v;
//     int weight;
// }edgeType;

// #define MAX_SIZE 20
// typedef struct{
//     edgeType edges[MAX_SIZE];
//     int lastNdx;
// }minHeapOrList;

// typedef struct{
//     minHeapOrList eList;
//     int cost;
// }Kruskal, Prim;

// void initMinHeap(minHeapOrList*);   //helper
// void createMinHeap(minHeapOrList*, LabelAdjMat);    //preliminary
// void insertMinHeap(int weight, int u, int v, minHeapOrList *);  //helper: inserts element in LabelAdjMat as newly created edgeType and heapify.
// edgeType deleteMinHeap(minHeapOrList *);    //preliminary
// void heapifySubtree(int index, minHeapOrList *);    //helper: given the index, heapifies its subtrees.
// void heapifyAll(minHeapOrList *);      //optional

// createMinHeap
// - initMinHeap
// - heapifyAll
// - - heapifySubtree
// deleteMinHeap
// - heapifySubtree

int main(){
    LabelAdjMat mat =
    {
        {INF, 1, 5, 4, 6},
        {1, INF, 5, 2, INF},
        {5, 5, INF, 1, 7},
        {4, 2, 1, INF, 3},
        {6, INF, 7, 3, INF}
    };
    MST list;
    minHeapOrList heap;
    createMinHeap(&heap, mat);   //heap contains the minimum heap of edgeType by their weight;
    print(heap);
}

