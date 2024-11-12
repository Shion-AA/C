#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 12

typedef struct {
    int list[SIZE];
    int lastNdx;
} Heap, *HeapPtr;

void print(Heap);
void heapifySubtree(Heap*, int);
void heapifyAll(Heap *H);
int getMinChild(HeapPtr, int);
int dequeue(HeapPtr);
void enqueue(HeapPtr, int);

int dequeue(HeapPtr H){
    int ret = -1;
    if(H->lastNdx != -1){
        ret = H->list[0];
        H->list[0] = H->list[H->lastNdx--];
        heapifySubtree(H, 0);
    }
    return ret;
}

void enqueue(HeapPtr H, int x){
    if(H->lastNdx < SIZE - 1){
        //insert at last, and then run heapify all. but I still think there might be a better way somehow...
        H->list[++H->lastNdx] = x;
        heapifyAll(H);
    }
}
void heapifyAll(HeapPtr H){
    int LLP = (H->lastNdx - 1) / 2;
    while(LLP != -1){
        heapifySubtree(H, LLP--);
    }
}

int getMinChild(HeapPtr H, int index) {
    int LC = index * 2 + 1;
    int RC = LC + 1;
    if(LC > H->lastNdx || LC < 0){LC = -1;};
    if(RC > H->lastNdx || RC < 0){RC = -1;};

    int retIndex = -1;

    if(LC != -1){
        if(RC != -1 && H->list[RC] < H->list[LC]){
            retIndex = RC;
        } else {
            retIndex = LC;
        }
    }
    return retIndex;
}

void heapifySubtree(HeapPtr H, int index){
    if(index != -1){
        int child = getMinChild(H, index);

        if (child != -1 && child <= H->lastNdx && H->list[child] < H->list[index]) {
            int temp = H->list[child];
            H->list[child] = H->list[index];
            H->list[index] = temp;
            heapifySubtree(H, child);
        }
    }
}

// void oldheapifySubtree(HeapPtr H, int index){
//     if(index != -1){
//         int swap = -1;
//         int LC = (index * 2) + 1;
//         int RC = (index + 1) * 2;
//         if(LC > H->lastNdx){       //LC doesnt exists
//             LC = -1;
//         }
//         if(RC > H->lastNdx){       //RC doesnt exists
//             RC = -1;
//         }
//         if(LC != -1){
//             swap = LC;
//         if(RC != -1 && H->list[LC] > H->list[RC]){
//             swap = RC;
//         }
//         }
//         if(swap != -1 && H->list[swap] < H->list[index]){
//             int temp = H->list[swap];
//             H->list[swap] = H->list[index];
//             H->list[index] = temp;
//             heapifySubtree(H, swap);
//         }
//     }
// }

void print(Heap H){
    int i;
    for(i = 0; i <= H.lastNdx; i++){
        printf("%d ", H.list[i]);
    }
    printf("\n");
}

int main(){
    Heap L;
    L.lastNdx = -1;
    int a[] =  {5,2,6,1,4,
                8,2,3,7,1,
                2,200,300,2,100};
    // memcpy(L.list, a, sizeof(a));
    // L.lastNdx = 8;

    // heapifyAll(&L);

    // print(L);

    int i;
    for(i = 0; i < sizeof(a) / sizeof(int); i++){
        enqueue(&L, a[i]);
    }
    print(L);

    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);
    printf("dequeued: %d\n", dequeue(&L));
    print(L);

}