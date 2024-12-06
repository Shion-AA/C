#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define INF 999

typedef int LabelAdjMat[MAX][MAX];
typedef struct {
    int u, v;
    int weight;
} edgeType;

#define MAX_SIZE 25
typedef struct {
    edgeType edges[MAX_SIZE];
    int lastNdx;
} minHeapOrList;

typedef struct {
    minHeapOrList eList;
    int cost;
} Kruskal, Prim;

void initMinHeap(minHeapOrList* heap);
void createMinHeap(minHeapOrList* heap, LabelAdjMat mat);
void insertMinHeap(int weight, int u, int v, minHeapOrList *heap);
edgeType deleteMinHeap(minHeapOrList *heap);
void heapifySubtree(minHeapOrList *H, int index);
void heapifyAll(minHeapOrList *H);
Prim matToPrim(LabelAdjMat);

void initMinHeap(minHeapOrList *heap) {
    heap->lastNdx = -1;
}

void createMinHeap(minHeapOrList *heap, LabelAdjMat mat) {
    initMinHeap(heap);
    int x, y;
    for (x = 0; x < MAX; x++) {
        for (y = x + 1; y < MAX; y++) {
            if (mat[x][y] != INF) {
                heap->edges[++heap->lastNdx].u = x;
                heap->edges[heap->lastNdx].v = y;
                heap->edges[heap->lastNdx].weight = mat[x][y];
            }
        }
    }
    heapifyAll(heap);
}

edgeType deleteMinHeap(minHeapOrList *heap) {
    edgeType min;
    min.weight = INF;
    min.u = -1;
    min.v = -1;
    if (heap->lastNdx >= 0) {
        min = heap->edges[0];
        heap->edges[0] = heap->edges[heap->lastNdx--];
        heapifySubtree(heap, 0);
    }
    return min;
}

void heapifyAll(minHeapOrList *H) {
    int LLP = (H->lastNdx - 1) / 2;
    while (LLP != -1) {
        heapifySubtree(H, LLP--);
    }
}

int getMinChild(minHeapOrList H, int index) {
    int LC = index * 2 + 1;
    int RC = LC + 1;
    if (LC > H.lastNdx || LC < 0) { LC = -1; }
    if (RC > H.lastNdx || RC < 0) { RC = -1; }

    int retIndex = -1;

    if (LC != -1) {
        if (RC != -1 && H.edges[RC].weight < H.edges[LC].weight) {
            retIndex = RC;
        } else {
            retIndex = LC;
        }
    }
    return retIndex;
}

void heapifySubtree(minHeapOrList *H, int index) {
    if (index != -1) {
        int child = getMinChild(*H, index);
        if (child != -1 && child <= H->lastNdx && H->edges[child].weight < H->edges[index].weight) {
            edgeType temp = H->edges[child];
            H->edges[child] = H->edges[index];
            H->edges[index] = temp;
            heapifySubtree(H, child);
        }
    }
}

void print(minHeapOrList H) {
    for (int i = 0; i <= H.lastNdx; i++) {
        printf("(%d, %d): %d\n", H.edges[i].u, H.edges[i].v, H.edges[i].weight);
    }
    printf("\n");
}

int main() {
    LabelAdjMat mat = {
        {INF, 1, 5, 4, 6},
        {1, INF, 5, 2, INF},
        {5, 5, INF, 1, 7},
        {4, 2, 1, INF, 3},
        {6, INF, 7, 3, INF}
    };
    minHeapOrList heap;
    createMinHeap(&heap, mat);
    print(heap);
    minHeapOrList emptyHeap;
    initMinHeap(&emptyHeap);
    heapifyAll(&emptyHeap);
    print(emptyHeap);

    Prim prim;
    prim = matToPrim(mat);
    // printf("debug");
    print(prim.eList);
}

// Prim matToPrim(LabelAdjMat mat){    //v1: create min-heap before finding MST
//     minHeapOrList heap;
//     createMinHeap(&heap, mat);
//     // int uni[MAX] = {1,1,1,1,1}; //bit vector for universal sets/all vertices
//     Prim MSP;
//     MSP.cost = 0;
//     initMinHeap(&(MSP.eList));
//     int uni = (1 << MAX) - 1;   //comp word implementation
//     int visited = 1;
//     edgeType x;
//     edgeType min;
//     int y;
//     while(visited != uni){
//         x = deleteMinHeap(&heap);
//         min.weight = INF;
//         for(y = 0; y <= heap.lastNdx; y++){
//             if(((1 << x.u) & visited) == x.u && ((1 << x.v) & visited) != x.v && x.weight < min.weight){
//                 printf("DEBUG");
//                 min = x;
//             }
//         }
//         visited += 1 << x.v;
//         MSP.cost += min.weight;
//         MSP.eList.edges[++MSP.eList.lastNdx] = min;
//     }
//     return MSP;
// }   //nvm I cant. move on to v2

Prim matToPrim(LabelAdjMat mat){
    int x, y;
    int visited[MAX] = {0,0,0,0,0};
    visited[0] = 1;     //random first node;
    Prim MST;
    MST.eList.lastNdx = -1;
    MST.cost = 0;
    edgeType minEdge;
    while(MST.eList.lastNdx < MAX - 2){
        minEdge.weight = INF;

        for(x = 0; x < MAX; x++){
            if(visited[x] == 1){
                for(y = 0; y < MAX; y++){
                    if(visited[y] == 0 && mat[x][y] < minEdge.weight){
                        minEdge.u = x;
                        minEdge.v = y;
                        minEdge.weight = mat[x][y];
                    }
                }
            }
        }
        if(minEdge.weight != INF){
            MST.cost += minEdge.weight;
            MST.eList.edges[++MST.eList.lastNdx] = minEdge;
            visited[minEdge.v] = 1;
        } else {
            printf("Error");
        }
    }
    return MST;
}