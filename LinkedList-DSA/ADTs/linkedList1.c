#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}*list;

void test1(list *A){
    int arr[] = {1,3,5};
    int count = 0;
    for(;count<(sizeof(arr)/4); count++){
        *A = (list)malloc(sizeof(struct node));
        (*A)->data = arr[count];
        A = &(*A)->next;
    }
    *A = NULL;
}
void test2(list *A){
    int arr[] = {1,1,1};
    int count = 0;
    for(;count<(sizeof(arr)/4); count++){
        *A = (list)malloc(sizeof(struct node));
        (*A)->data = arr[count];
        A = &(*A)->next;
    }
    *A = NULL;
}
void test3(list *A){
    int arr[] = {1};
    int count = 0;
    for(;count<(sizeof(arr)/4); count++){
        *A = (list)malloc(sizeof(struct node));
        (*A)->data = arr[count];
        A = &(*A)->next;
    }
    *A = NULL;
}
void printList(list *A){
    while(*A != NULL){
        printf("%d, ", (*A)->data);
        A = &(*A)->next;
    }
}
void insertLast(int x, list *A){
    list *trav;
    for(trav = A; *trav != NULL && (*trav)->data != x; trav = &(*trav)->next){}
    if(*trav == NULL){
        list newNode = (list)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;
        *trav = newNode;
    }
}
void deleteFirstOccurence(int x, list *A){
    list *trav = A;
    for(; *trav != NULL && (*trav)->data != x; trav = &(*trav)->next){}
    if(*trav != NULL){
        *trav = (*trav)->next;
    }
}
void main(){
    int insertLastElem = 2;
    list L = NULL;

    test1(&L);
    // insertLast(insertLastElem, &L);
    printList(&L);
    printf("\n");
    deleteFirstOccurence(1, &L);
    printList(&L);
}