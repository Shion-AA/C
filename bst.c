#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * LC;
    struct node * RC;
}*NodePtr, Node;

void insert(NodePtr*, int);
void print(NodePtr);

int main(){
    NodePtr root = NULL;
    insert(&root, 5);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 9);
    insert(&root, 10);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 1);
    print(root);
}

void insert(NodePtr* root, int x){
    //always insert into leaf?
    NodePtr temp = (NodePtr) malloc(sizeof(Node));
    temp->val = x;
    temp->LC = NULL;
    temp->RC = NULL;
    NodePtr * trav = root;
    for(;(*trav) != NULL && (*trav)->val != x;trav = (x < (*trav)->val) ? &(*trav)->LC : &(*trav)->RC){}
    if(*trav == NULL){
        *trav = temp;
    } else {
        printf("Duplicate entry found, exiting without inserting.[%d]\n", x);
    }
}

void print(NodePtr root){
    if(root->LC != NULL){
        print(root->LC);
    }
    printf("%d ", root->val);
    if(root->RC != NULL){
        print(root->RC);
    }
}