#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void printArr(int arr[]);

int main(){
    int inputArray[MAX] = {923,2,3,1,66,1,3,7,9,0};
    int min, minNdx = 0;
    int x, y, temp;
    for(x = 0; x < MAX; x++){
        min = inputArray[x];
        minNdx = x;
        for(y = x; y < MAX; y++){
            if(inputArray[y] < min){
                min = inputArray[y];
                minNdx = y;
            }
        }
        if(minNdx != x){
            temp = inputArray[minNdx];
            inputArray[minNdx] = inputArray[x];
            inputArray[x] = temp;
        }
    }

    printArr(inputArray);
}

void printArr(int arr[]){
    int x;
    for(x = 0; x < MAX; x++){
        printf("%d ", arr[x]);
    }
}