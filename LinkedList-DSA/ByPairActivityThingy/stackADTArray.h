#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct {
    int elem[MAX];
    int top;
} Stack;

void initialize (Stack *A){
    A->top = -1;
}

bool isFull(Stack A){
    return (A.top == MAX -1) ? true : false;
}
bool isEmpty(Stack A){
    return (A.top == -1) ? true : false;
}

void push(Stack *A, int x){
    if(!isFull(*A)){
        A->elem[++A->top] = x;
    }
}

void pop(Stack *A){
    if(!isEmpty(*A)){
        A->top--;
    }
}

int peek(Stack A){
    return (!isEmpty(A)) ? A.elem[A.top] : -1;
}

// void insertBottom(Stack *A, int x){
//     if(!isFull(*A)){
//         int i;
//         for(i = A->top; i > 0; i--){
//             A->elem[i] = A->elem[i-1];
//         }
//         A->elem[0] = x;
//     }
// }

// void printList(Stack A){
//     printf("top -> ");
//     while(A.top > -1){
//         printf("%d, ", A.elem[A.top]);
//         A.top--;
//     }
//     printf("<- bottom\n");
// }

#endif