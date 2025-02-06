#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 9

typedef struct {
    int list[SIZE];
    int lastNdx;
} Heap;

void print(Heap);
void heapifySubtree(Heap*, int);
void heapifyAll(Heap *H);

void main(){
    Heap L;
    int a[] =  {2,3,4,5,6,7,8,9,1};     //binary balanced tree
    memcpy(L.list, a, sizeof(a));
    L.lastNdx = 8;

    heapifyAll(&L);

    print(L);
}
void heapifyAll(Heap *H){
    int LLP = (H->lastNdx - 1) / 2;
    while(LLP != -1){
        heapifySubtree(H, LLP--);
    }
}
void heapifySubtree(Heap *H, int index){
    if(index != -1){
        int swap = -1;
        int LC = (index * 2) + 1;
        int RC = (index + 1) * 2;

        if(LC >= SIZE){       //LC doesnt exists
            LC = -1;
        }
        if(RC >= SIZE){       //RC doesnt exists
            RC = -1;
        }

        if(LC != -1){
            swap = LC;
        if(RC != -1 && H->list[LC] > H->list[RC]){
            swap = RC;
        }
        }
        if(swap != -1 && H->list[swap] < H->list[index]){
            int temp = H->list[swap];
            H->list[swap] = H->list[index];
            H->list[index] = temp;
            heapifySubtree(H, swap);
        }
    }
}

void print(Heap H){
    int i;
    for(i = 0; i <= H.lastNdx; i++){
        printf("%d ", H.list[i]);
    }
    printf("\n");
}