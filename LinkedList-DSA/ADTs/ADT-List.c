#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8

typedef struct node {
    int data;
    struct node * next;
}*list;

void populate(list *A);
void printList(list *A);

int get(list *A, int pos);
void insert(list *A, int pos, int elem);
void removeFirst(list *A, int elem);
void removeAt(list *A, int pos);
void replace(list *A, int pos, int elem);
int size(list *A);
bool isEmpty(list *A);
bool isFull(list *A);
bool isValid(list *A, int pos);

void populate(list *A){
    printf("List populated\n");
    int arr[] = {1,2,3,4,5,6,7};
    int count;
    for(count=0; count<(sizeof(arr)/sizeof(int)); count++){
        *A = (list)malloc(sizeof(struct node));
        (*A)->data = arr[count];
        A = &(*A)->next;
    }
    *A = NULL;
}
void printList(list *A){
    int nodeNum;
    nodeNum = size(A);
    printf("Current List");
    if(nodeNum != 0){
        printf("[%dnode(s)]: ", nodeNum);
        while(*A != NULL){
            printf("%d ", (*A)->data);
            A = &(*A)->next;
        }
    } else {
        printf(": [Empty]");
    }
    printf("\n\n");
}
bool isValid(list *A, int pos){
    if(pos < 1 || pos > size(A)){
        return false;
    } else {
        return true;
    }
}
bool isEmpty(list *A){
    if(*A == NULL){
        return true;
    } else {
        return false;
    }
}
bool isFull(list *A){
    int count = 0;
    for(;*A != NULL; A = &(*A)->next, count++){}
    if(count >= MAX){
        return true;
    } else {
        return false;
    }
}
int size(list *A){
    int size = 0;
    while(*A != NULL){
        size++;
        A = &(*A)->next;
    }
    return size;
}
int get(list *A, int pos){
    printf("Get: ");
    if(isValid(A, pos)){
        for(;pos > 1; A = &(*A)->next, pos--){}
        printf("[%d] Returned.\n", (*A)->data);
        return (*A)->data;
    } else {
        printf("[false] Invalid position in the list.\n");
        return -1;
    }
}
void insert(list *A, int pos, int elem){
    printf("Insert: ");
    if(isValid(A, pos) && !isFull(A)){
        printf("[pos %d, element %d] inserted.\n", pos, elem);
        for(;pos > 1; A = &(*A)->next, pos--){}
        list newNode = (list)malloc(sizeof(struct node));
        newNode->data = elem;
        newNode->next = *A;
        *A = newNode;
    } else {
        printf("[fault]\n");
    }
}
void replace(list *A, int pos, int elem){
    printf("Replace: ");
    if(isValid(A, pos)){
        printf("[pos %d, element %d] replaced.\n", pos, elem);
        for(;pos > 1; A = &(*A)->next, pos--){}
        (*A)->data = elem;
    } else {
        printf("[fault]\n");
    }
}
void removeFirst(list *A, int elem){
    printf("Remove: ");
    if(!isEmpty(A)){
        for(;*A != NULL && (*A)->data != elem; A = &(*A)->next){}
        if(*A != NULL){
            printf("The first occurence of [%d] removed.\n", (*A)->data);
            list freePtr = *A;
            *A = (*A)->next;
            free(freePtr);
        } else {
            printf("[%d] No such element found.\n", elem);
        }
    }
}
void removeAt(list *A, int pos){
    printf("Remove At: ");
    if(isValid(A, pos)){
        printf("[pos = %d] removed.\n", pos);
        for(;pos > 1; A = &(*A)->next, pos--){}
        list freePtr = *A;
        *A = (*A)->next;
        free(freePtr);
    } else {
        printf("[fault]\n");
    }
}
void main(){
    list head = NULL;
    populate(&head);
    printList(&head);

    get(&head, 1);
    printList(&head);

    insert(&head, 2, 10);
    printList(&head);

    replace(&head, 0, 11);
    replace(&head, 8, 12);
    printList(&head);

    removeFirst(&head, 1);
    printList(&head);

    removeAt(&head, 5);
    removeAt(&head, 1);
    removeAt(&head, 1);
    removeAt(&head, 1);
    removeAt(&head, 1);
    removeAt(&head, 1);
    removeAt(&head, 1);
    removeAt(&head, 1);
    replace(&head, 1, 1);
    printList(&head);
}