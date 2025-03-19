#include <stdio.h>
#include <stdlib.h>

#define RANGE 50

typedef struct Node{
    int val;
    struct Node* next;
}node;

void bucketSort(int*, int, int);
void insertionSortLL(node **);

void printArray(int arr[], int n){
    printf("\n");
    int i;
    for(i= 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {1,55,11,9,0, 40,49,21,21,1}; //range:0-49
    int n = sizeof(arr) / sizeof(int);
    int num_of_bucket = 5;
    bucketSort(arr, n, num_of_bucket); //5 buckets for range
    printArray(arr, n);
    return 0;
}

void bucketSort(int arr[], int n, int num_of_bucket){
    node ** bucket = calloc(num_of_bucket, sizeof(node *));

    int i, pos;
    int bucketRange = (RANGE / num_of_bucket);
    node * temp;
    for(i = 0 ; i < n; i++){
        pos = arr[i] / bucketRange;
        temp = (node*) malloc(sizeof(node));
        temp->val = arr[i];
        temp->next = bucket[pos];
        bucket[pos] = temp;
    }

    for(i = 0; i < num_of_bucket; i++){
        insertionSortLL(&bucket[i]);
    }

    int index = 0;
    for (i = 0; i < num_of_bucket; i++) {
        temp = bucket[i];
        while (temp) {
            arr[index++] = temp->val;
            node* prev = temp;
            temp = temp->next;
            free(prev); // Free memory
        }
    }

    free(bucket); // Free bucket array

}

void insertionSortLL(node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    node* sorted = NULL;  // New sorted list
    node* current = *head; // Traverses the original list

    while (current) {
        node* next = current->next;
        
        // Insert current node into sorted linked list
        if (!sorted || current->val < sorted->val) {
            current->next = sorted;
            sorted = current;
        } else {
            node* temp = sorted;
            while (temp->next && temp->next->val < current->val)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted; // Update head to new sorted list
}
