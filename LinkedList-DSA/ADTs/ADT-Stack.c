#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8

typedef struct node {
    int data;
    struct node * next;
}*list;

void populate(list *A){
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
    printf("\n");
    while(*A != NULL){
        printf("%d, ", (*A)->data);
        A = &(*A)->next;
    }
}
bool isEmpty(list *A){
    if(*A != NULL){
        return false;
    } else {
        return true;
    }
}
bool isFull(list *A){
    int count = 0;
    list *trav = A;
    while(*trav != NULL){
        trav = &(*trav)->next;
        count++;
    }
    if(count < MAX){
        return false;
    } else {
        return true;
    }
}
void push(int x, list *A){
    if(!isFull(A)){
        list *trav = A;
        for(;*trav != NULL;trav = &(*trav)->next){}
        *trav = (list)malloc(sizeof(struct node));
        (*trav)->data = x;
        (*trav)->next = NULL;
    } else {
        printf("\nThe list is full.");
    }
}
void pop(list *A){
    if(!isEmpty(A)){
        list *trav = A;
        for(;(*trav)->next != NULL;trav = &(*trav)->next){}
        free(*trav);
        *trav = NULL;
    } else {
        printf("The list is empty.");
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
    int element;
    if(!isEmpty(A)){
        for(;(*A)->next != NULL;A = &(*A)->next){}
        element = (*A)->data;
    } else {
        printf("The list is empty.");
    }
    return element;
}
int main(){
    list head = NULL;
    int listSize, elementTop;
    populate(&head);
    printList(&head);
    push(9, &head);
    printList(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    printList(&head);
    listSize = size(&head);
    printf("\nThe size of list is : %d", listSize);
    elementTop = peek(&head);
    printf("\nThe element on top of this list is : %d", elementTop);
}