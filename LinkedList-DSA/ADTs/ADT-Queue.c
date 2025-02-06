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
bool isEmpty(list *A);
bool isFull(list *A);
int size(list *A);
int peek(list *A);
void enqueue(int elem, list *A);
int dequeue(list *A);

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
int peek(list *A){
    printf("Peek element: ");
    int element;
    if(!isEmpty(A)){
        element = (*A)->data;
        printf("[%d]\n", element);
    } else {
        printf("[False] The list is empty.\n");
    }
    return element;
}
void enqueue(int elem, list *A){
    printf("Enqueue:");
    if(!isFull(A)){
        for(;*A != NULL; A = &(*A)->next){}
        *A = (list)malloc(sizeof(struct node));
        (*A)->data = elem;
        (*A)->next = NULL;
        printf("[Success] Enqueued %d\n", elem);
    } else {
        printf("[False] The list is full.\n");
    }
}
int dequeue(list *A){
    int returnElem;
    printf("Dequeue:");
    if(!isEmpty(A)){
        list freePtr = *A;
        returnElem = (*A)->data;
        *A = (*A)->next;
        free(freePtr);
        printf("[Success] Returned element: %d\n", returnElem);
    } else {
        printf("[False] The list is empty\n");
    }
    return returnElem;
}

int main(){
    list head = NULL;
    populate(&head);
    printList(&head);

    enqueue(8, &head);
    printList(&head);

    enqueue(9, &head);
    printList(&head);

    peek(&head);
    dequeue(&head);
    printList(&head);

    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    peek(&head);
    printList(&head);

    enqueue(10, &head);
    printList(&head);
}