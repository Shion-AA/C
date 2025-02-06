#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// typedef struct {    //V1 and V2 definition
//     char elem[MAX];
//     int count;
// } List;

typedef struct {    //V3 and V4
    char *elem;
    int count;
    int ArrSize;
} List;

void initV1(List *L){
    L->count = 0;
}
void initV2(List **L){
    *L =(List*)malloc(sizeof(List));
    (*L)->count = 0;
}
void initV3(List *L){
    L->count = 0;
    L->ArrSize = MAX;
    L->elem = (char*)malloc(MAX);
    L->elem[0] = 'A';
    L->elem[1] = 'B';
    L->elem[2] = 'C';
}
void initV4(List **L){
    *L = (List*)malloc(sizeof(List));
    (*L)->count = 0;
    (*L)->ArrSize = MAX;
    (*L)->elem = (char*)malloc(MAX);
    (*L)->elem[0] = 'Y';
    (*L)->elem[1] = 'A';
    (*L)->elem[2] = 'Y';
}

// insert(x,p,L);
//For V1 and V2
void insert1(char x, int p, List* L){
    if(L->count < MAX){                         //if the list is max
        if(p <= L->count && p >= 0){            //if the given pos is valid
            int i = L->count;
            for(; i > p; i--){
                L->elem[i] = L->elem[i - 1];
            }
            L->elem[i] = x;
            L->count++;
        } else {
            printf("Invalid Position\n");
        }
    } else {
        printf("The list is full\n");
    }
}

void delete(int p, List *A){
    if(p>=0 && p < A->count && A->count > 0){
        for(--A->count; p < A->count; p++){
            A->elem[p] = A->elem[p+1];
        }
    }
}

void printList(List L){
    int i = 0;
    for(; L.count > 0; L.count--){
        printf("%c", L.elem[i++]);
    }
    printf("\n");
}
int main(){
    List L; //version 1
    initV1(&L);
    insert1('A',0,&L);
    insert1('B',1,&L);
    insert1('C',2,&L);
    printList(L);
    delete(0, &L);
    printList(L);

    // List *L;
    // initV2(&L);
    // insert1('A',0,L);
    // insert1('B',1,L);
    // insert1('C',2,L);
    // printList(*L);

    // List L;
    // initV3(&L);
    // printf("%c", L.elem[0]);
    // printf("%c", L.elem[1]);
    // printf("%c", L.elem[2]);

    // List *L;
    // initV4(&L);
    // printf("%c", L->elem[0]);
    // printf("%c", L->elem[1]);
    // printf("%c", L->elem[2]);
}