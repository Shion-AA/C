#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
   int data; 
   struct node *next; 
}*List;

void printList(List *A){
    printf("Current List: ");
    while(*A != NULL){
        printf("%d ", (*A)->data);
        A = &(*A)->next;
    }
    printf("\n\n");
}

void initListWithHeader(List *A){
    *A = (List)malloc(sizeof(struct node));
    (*A)->next = NULL;
}
void initListNoHeader(List *A){
    *A = NULL;
}

void insertLast1(List A, int elem){
    while(A->next != NULL){
        A = A->next;
    }
    A->next = (List)malloc(sizeof(struct node));
    A->next->data = elem;
    A->next->next = NULL;
}
void insertLast2a(List *A, int elem){
    for(; *A != NULL; A = &(*A)->next){}
    *A = (List)malloc(sizeof(struct node));
    (*A)->data = elem;
    (*A)->next = NULL;
}
void insertLast2b(List *A, int elem){
    if(*A == NULL){
        *A = (List)malloc(sizeof(struct node));
        (*A)->data = elem;
        (*A)->next = NULL;
    } else if((*A)->next == NULL){
        (*A)->next = (List)malloc(sizeof(struct node));
        (*A)->next->data = elem;
        (*A)->next->next = NULL;
    } else {
        for(; (*A)->next != NULL; A = &(*A)->next){}
        (*A)->next = (List)malloc(sizeof(struct node));
        (*A)->next->data = elem;
        (*A)->next->next = NULL;
    }
}
void deleteElem1(List *A, int elem){
    for(; *A != NULL && (*A)->data != elem; A = &(*A)->next){}
    if(*A != NULL){
        *A = (*A)->next;
    }
}
void deleteElem2(List *A, int elem){
    if(*A != NULL){
        if((*A)->data == elem){
            *A = (*A)->next;
        } else {
            for(; (*A)->next != NULL && (*A)->next->data != elem; A = &(*A)->next){}
            if((*A)->next != NULL){
                (*A)->next = (*A)->next->next;
            }
        }
    }
}
void main(){
    List L;
    initListNoHeader(&L);
    insertLast2b(&L, 3);
    insertLast2b(&L, 2);
    insertLast2b(&L, 1);
    insertLast2b(&L, 1);
    insertLast2b(&L, 8);
    deleteElem2(&L, 8);
    printList(&L);
}