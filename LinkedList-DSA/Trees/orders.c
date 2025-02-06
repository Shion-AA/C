 #include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * LC;
    struct node * RC;
} Node, *NodePtr;

#define SIZE 10

void populate(NodePtr* A){
    //6,4,2,1,7,9,1,0,5,2
    *A = (NodePtr)calloc(1, sizeof(Node));
    (*A)->val = 6;

    (*A)->LC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->LC->val = 4;

    (*A)->LC->LC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->LC->LC->val = 2;

    (*A)->LC->RC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->LC->RC->val = 1;

    (*A)->LC->RC->LC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->LC->RC->LC->val = 7;

    (*A)->RC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->RC->val = 9;

    (*A)->RC->LC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->RC->LC->val = 1;

    (*A)->RC->RC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->RC->RC->val = 0;

    (*A)->RC->RC->LC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->RC->RC->LC->val = 5;

    (*A)->RC->RC->RC = (NodePtr)calloc(1, sizeof(Node));
    (*A)->RC->RC->RC->val = 2;

}

void preorder(NodePtr root){
    printf("%d ", root->val);
    if(root->LC != NULL)
        preorder(root->LC);
    if(root->RC != NULL)
        preorder(root->RC);
}

void inorder(NodePtr root){
    if(root->LC != NULL)
        inorder(root->LC);
    printf("%d ", root->val);
    if(root->RC != NULL)
        inorder(root->RC);
}

void postorder(NodePtr root){
    if(root->LC != NULL)
        postorder(root->LC);
    if(root->RC != NULL)
        postorder(root->RC);
    printf("%d ", root->val);
}

int main(){
    NodePtr root;
    populate(&root);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    //nice!done!
}