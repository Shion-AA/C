#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void printArr(int arr[]);

int main(){
    int inputArray[MAX] = {5,1,2,7,9,2,4,7,2,10};
    int i, j, temp;
    for(i = 1; i < MAX; i++){
        for(j = i; j > 0 && inputArray[j] < inputArray[j - 1]; j--){
            temp = inputArray[j];
            inputArray[j] = inputArray[j-1];
            inputArray[j-1] = temp;
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