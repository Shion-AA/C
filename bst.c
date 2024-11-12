#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * LC;
    struct node * RC;
}*NodePtr, Node;

int deleteMin(NodePtr*);
int deleteMax(NodePtr*);
void delete(NodePtr*, int);
NodePtr* find(NodePtr*, int);        //optional function - returns the address of the node if such exists. otherwise returns address of suggested location.
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
    printf("\n");

    delete(&root, 1);
    delete(&root, 5);
    delete(&root, 3);
    delete(&root, 4);
    delete(&root, 10);
    print(root);
    printf("\n");

    insert(&root, 12);
    insert(&root, 410);
    insert(&root, 50);
    insert(&root, 5);
    insert(&root, 100);
    insert(&root, 22);
    insert(&root, 1);
    insert(&root, 33);
    print(root);
    printf("\n");
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

void delete(NodePtr *root, int x){
    NodePtr* location = find(root, x);
    if(*location != NULL){
        if((*location)->LC != NULL){
            (*location)->val = deleteMax(&(*location)->LC);
        } else if((*location)->RC != NULL){
            (*location)->val = deleteMin(&(*location)->RC);
        } else {
            NodePtr temp = *location;
            *location = NULL;
            free(temp);
        }
    } else {
        printf("[%d] such node not found.\n", x);
    }
}

int deleteMin(NodePtr *RC){
    for(;(*RC)->LC != NULL; RC = &(*RC)->LC){}
    int ret = (*RC)->val;
    NodePtr temp = *RC;
    *RC = (*RC)->RC;
    free(temp);
    return ret;
}

int deleteMax(NodePtr *LC){
    for(;(*LC)->RC != NULL; LC = &(*LC)->RC){}
    int ret = (*LC)->val;
    NodePtr temp = *LC;
    *LC = (*LC)->LC;
    free(temp);
    return ret;
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

NodePtr* find(NodePtr* root, int x){
    NodePtr* trav = root;
    for(;*trav != NULL && (*trav)->val != x; trav = (x < (*trav)->val) ? &(*trav)->LC : &(*trav)->RC){}
    return trav;
}