#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 9999

void printArray(int arr[], int n){
    printf("\n");
    int i;
    for(i= 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void offlineTournamentSort(int inputArray[], int n){
    int node = n + n -1;
    int heap[node];
    memcpy(&heap[n], &inputArray[0], n * sizeof(int));
    // printArray(heap, node);
    
    // printf("%d\n",n );

    int i, j, index;
    for(i = 0; i < n; i++){
        for(index = node - 1; index > 0; index -= 2){
            if(index > n){      //if leaf node
                if(heap[index - 1] <= heap[index]){
                    heap[index / 2] = index - 1; //parent node gets smaller value child node
                } else {
                    heap[index / 2] = index;
                }
            } else {
                if(heap[heap[index-1]] <= heap[heap[index]]){
                    heap[index / 2] = heap[index - 1];
                } else {
                    heap[index / 2] = heap[index];
                }
            }
            printArray(heap, node);
        }
        inputArray[i] = heap[heap[0]];
        heap[heap[0]] = INF;
        // printArray(heap, node);
    }
    printArray(inputArray, n);
    // printArray(heap, node);
}

void tournamentSort(int inputArray[], int n, int type){
    if(type == 0){
        offlineTournamentSort(inputArray, n);
    } else {
        // onlineTournamentSort(inputArray);
    }
}

int main(){
    int inputArray[] = {9,1,1,2,5,2,7,1,9,0,1,5,7,7,3,8};

    tournamentSort(inputArray, sizeof(inputArray)/sizeof(int), 0); //0 indicates offline tournament sort

}