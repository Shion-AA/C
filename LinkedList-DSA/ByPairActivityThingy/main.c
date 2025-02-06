#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADTArray.h"
// #include "stackADTLinkedList.h"

void insertBottom(Stack *A, int x){
    if(!isFull(*A)){
        Stack temp;
        initialize(&temp);
        while(!isEmpty(*A)){
            push(&temp, peek(*A));
            pop(A);
        }
        push(A, x);
        while(!isEmpty(temp)){
            push(A, peek(temp));
            pop(&temp);
        }
    }
}

void displayList(Stack A){
        Stack temp;
        int x;
        initialize(&temp);
        while(!isEmpty(A)){
            x = peek(A);
            printf("|\t%d\t|\n", x);
            push(&temp, x);
            pop(&A);
        }
        printf("-----------------\n");
        while(!isEmpty(temp)){
            push(&A, peek(temp));
            pop(&temp);
        }
}

void main(){
    Stack s;
    initialize(&s);
    int populate[] = {10,5,4,3,2,1,0,9,8,7};
    int x, size = sizeof(populate) / sizeof(int);
    for(x = 0; x < size; x++){
        push(&s, populate[x]);
    }

    insertBottom(&s, 99);
    displayList(s);
    pop(&s);
    displayList(s);
    insertBottom(&s, 98);
    displayList(s);
}