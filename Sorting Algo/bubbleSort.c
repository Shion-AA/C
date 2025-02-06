#include <stdio.h>
#include <stdlib.h>
#define MAX 14
void printArr(int arr[]);

int main(){
    int inputArray[MAX] = {2,1,7,8,1,1,11,2,3,75,7,5,3,0};
    int temp = 0;
    int x, y;
    for(x = 0; x < MAX; x++){
        for(y = 0; y < MAX - 1 - x; y++){
            if(inputArray[y] > inputArray[y+1]){
                temp = inputArray[y];
                inputArray[y] = inputArray[y+1];
                inputArray[y+1] = temp;
            }   
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