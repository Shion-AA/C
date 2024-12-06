#include "helper.h"

void createMinHeap(minHeapOrList *heap, LabelAdjMat mat){
    initMinHeap(heap);
    int x, y;
    for(x = 0; x < MAX; x++){
        for(y = x + 1; y < MAX; y++){
            if(mat[x][y] != INF){
                // insertMinHeap(mat[x][y], x, y, heap);       //insertMinHeap(int weight, int u, int v, minHeapOrList *heap);
                //or...
                heap->edges[heap->lastNdx].u = x;
                heap->edges[heap->lastNdx].v = y;
                heap->edges[heap->lastNdx++].weight = mat[x][y];
                //insert each, and then later heapifyAll
            }
        }
    }
    heapifyAll(heap);   //heapifyAll(minHeapOrList *heap)
}

edgeType deleteMinHeap(minHeapOrList *heap){
    edgeType min;
    min.weight = INF;
    min.u = -1;
    min.v = -1;
    if(heap->lastNdx > -1){
        min = heap->edges[0];
        edgeType * temp = &(heap->edges[heap->lastNdx--]);
        heap->edges[0] = *temp;
        free(temp);
        heapifySubtree(0, heap);    //heapifySubtree(int index, minHeapOrList *heap)
    }
    return min;
}

void heapifyAll(minHeapOrList *H){
    int LLP = (H->lastNdx - 1) / 2;
    while(LLP != -1){
        heapifySubtree(H, LLP--);
    }
}

int getMinChild(minHeapOrList H, int index) {
    int LC = index * 2 + 1;
    int RC = LC + 1;
    if(LC > H.lastNdx || LC < 0){LC = -1;};
    if(RC > H.lastNdx || RC < 0){RC = -1;};

    int retIndex = -1;

    if(LC != -1){
        if(RC != -1 && H.edges[RC].weight < H.edges[LC].weight){
            retIndex = RC;
        } else {
            retIndex = LC;
        }
    }
    return retIndex;
}

void heapifySubtree(minHeapOrList * H, int index){
    if(index != -1){
        int child = getMinChild(*H, index);

        if (child != -1 && child <= H->lastNdx && H->edges[child].weight < H->edges[index].weight) {
            edgeType temp = H->edges[child];
            H->edges[child] = H->edges[index];
            H->edges[index] = temp;
            heapifySubtree(H, child);
        }
    }
}

void print(minHeapOrList H){
    int i;
    for(i = 0; i <= H.lastNdx; i++){
        printf("%d ", H.edges[i].weight);
    }
    printf("\n");
}