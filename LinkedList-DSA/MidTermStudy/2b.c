#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[48];
    char course[8];
    int yearLevel;
}info;

typedef struct node {
    info data;
    struct node *link;
}*Stack;


Stack popBSMATH(Stack *A){
    Stack tempList = NULL;
    Stack *tempPtr = &tempList;

    Stack retList = NULL;
    Stack *retPtr = &retList;

    while((*A) != NULL){
        if(strcmp((*A)->data.course , "BSMATH") == 0){
            *retPtr = *A;
            *A = (*retPtr)->link;
            retPtr = &(*retPtr)->link;
        } else {
            *tempPtr = *A;
            *A = (*tempPtr)->link;
            tempPtr = &(*tempPtr)->link;
        }
    }
    *tempPtr= NULL;
    *retPtr = NULL;

    while(tempList != NULL){
        *A = tempList;
        tempList = tempList->link;
        A = &(*A)->link;
    }
    *A = NULL;

    return retList;
}

int main(){
    //Hard code populate...
    Stack list = (Stack)malloc(sizeof(struct node));
    strcpy(list->data.course, "BSMATH");
    strcpy(list->data.name, "Shion");
    list->data.yearLevel = 1;

    list->link = (Stack)malloc(sizeof(struct node));
    strcpy(list->link->data.course, "BSIT");
    strcpy(list->link->data.name, "Suzuki");
    list->link->data.yearLevel = 2;

    list->link->link  = (Stack)malloc(sizeof(struct node));
    strcpy(list->link->link->data.course, "BSMATH");
    strcpy(list->link->link->data.name, "Myk");
    list->link->link->data.yearLevel = 3;
    list->link->link->link = NULL;

    // printf("%s, %s, %s", list->data.name, list->link->data.name, list->link->link->data.name);

    Stack bsmath = popBSMATH(&list);

    Stack trav = list;
    while(trav != NULL){
        printf("%s - %s\n", trav->data.name, trav->data.course);
        trav = trav->link;
    }
    printf("\n\n");
    trav = bsmath;
    while(trav != NULL){
        printf("%s - %s\n", trav->data.name, trav->data.course);
        trav = trav->link;
    }
}