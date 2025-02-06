#ifndef BASICFUNCTIONS_C
#define BASICFUNCTIONS_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

void clearInputBuffer() {
    while ((getchar()) != '\n' && getchar() != EOF);
}

//range is inclusive value
int randValue(int range, int min){
    int randomValue = 0;
    srand(time(0));
    randomValue = rand() % range + min;
    printf("TEST random value of %d generated", randomValue);
    return randomValue;
}

#endif