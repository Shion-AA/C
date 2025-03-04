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
    int node = n + n - 1;
    int heap[node];
    memcpy(&heap[n - 1], &inputArray[0], n * sizeof(int));
    // printArray(heap, node);
    
    // printf("%d\n",n );

    int i, j, index;
    for(i = 0; i < n; i++){
        for(index = n - 2; index > n - 2 - n / 2; index--){     //start from the least parent node, to the root node
            if(heap[index * 2 + 1] <= heap[index * 2 + 2]){
                heap[index] = index * 2 + 1;
            } else {
                heap[index] = index * 2 + 2;
            }
            printArray(heap, node);
        }
        for(; index >= 0; index--){     // from here, treat value as index
            if(heap[heap[index * 2 + 1]] <= heap[heap[index * 2 + 2]]){
                heap[index] = heap[index * 2 + 1];
            } else {
                heap[index] = heap[index * 2 + 2];
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



//GPT CODE (WORKING)
// #include <stdio.h>
// #include <string.h>

// #define INF 9999

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void buildTournamentTree(int heap[], int n) {
//     // Build the tournament tree
//     for (int i = n - 2; i >= 0; i--) {
//         if (heap[2 * i + 1] <= heap[2 * i + 2]) {
//             heap[i] = heap[2 * i + 1];
//         } else {
//             heap[i] = heap[2 * i + 2];
//         }
//     }
// }

// void updateTournamentTree(int heap[], int n, int index) {
//     // Update the tournament tree after removing the smallest element
//     int parent = (index - 1) / 2;
//     while (parent >= 0) {
//         if (heap[2 * parent + 1] <= heap[2 * parent + 2]) {
//             heap[parent] = heap[2 * parent + 1];
//         } else {
//             heap[parent] = heap[2 * parent + 2];
//         }
//         if (parent == 0) break;
//         parent = (parent - 1) / 2;
//     }
// }

// void offlineTournamentSort(int inputArray[], int n) {
//     int nodeCount = 2 * n - 1;
//     int heap[nodeCount];

//     // Initialize leaf nodes with input array and internal nodes with INF
//     for (int i = 0; i < n; i++) {
//         heap[n - 1 + i] = inputArray[i];
//     }
//     for (int i = 0; i < n - 1; i++) {
//         heap[i] = INF;
//     }

//     // Build the initial tournament tree
//     buildTournamentTree(heap, n);

//     // Extract elements in sorted order
//     for (int i = 0; i < n; i++) {
//         // The root of the tree contains the smallest element
//         inputArray[i] = heap[0];

//         // Find the index of the leaf node that contains this element
//         int index = n - 1;
//         while (index < nodeCount && heap[index] != heap[0]) {
//             index++;
//         }

//         // Set this leaf node to INF to mark it as processed
//         heap[index] = INF;

//         // Update the tournament tree
//         updateTournamentTree(heap, n, index);
//     }
// }

// int main() {
//     int inputArray[] = {9, 1, 1, 2, 5, 2, 7, 1, 9, 0, 1, 5, 7, 7, 3, 8};
//     int n = sizeof(inputArray) / sizeof(inputArray[0]);

//     printf("Original array:\n");
//     printArray(inputArray, n);

//     offlineTournamentSort(inputArray, n);

//     printf("Sorted array:\n");
//     printArray(inputArray, n);

//     return 0;
// }
