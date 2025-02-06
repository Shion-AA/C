#ifndef StackADTLinkedList_H
#define StackADTLinkedList_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct node {
    int elem;
    struct node * next;
} *Stack;

void initialize(Stack * L){
    *L = NULL;
}

void push(Stack * L, int value){
    Stack temp = (Stack) malloc (sizeof(struct node));
    temp->elem = value;
    temp->next = *L;
    *L = temp;
}
void pop(Stack * L){
    if (*L != NULL){
        Stack temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
int peek(Stack L){
    return (L != NULL) ? L->elem : -1;
}
bool isEmpty(Stack L){
    return (L == NULL) ? true : false;
}
bool isFull(Stack L){
    return false;
}

#endif