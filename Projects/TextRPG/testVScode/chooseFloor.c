#ifndef CHOOSEFLOOR_C
#define CHOOSEFLOOR_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#include "header.h"
#include "basicFunctions.c"
bool chooseFloor(int * stage)
{
    char inp;
    int rng;

    printf("\nFirst floor...You see 3 ways ahead...\nThe route: \n(1) Left\n(2) Center\n(3) Right\n");
    scanf(" %c", &inp);
    clearInputBuffer();
    system("cls");
    switch (inp)
    { // Choose 1,2,3 path
    case '1':
    case 'l':
    case 'L':
        printf("You have chosen the LEFT path");
        rng = randValue(3, 1);
        break;
    case '2':
    case 'c':
    case 'C':
        printf("You have chosen the CENTER path");
        rng = randValue(3, 1);
        break;
    case '3':
    case 'r':
    case 'R':
        printf("You have chosen the RIGHT path");
        rng = randValue(3, 1);
        break;
    default:
        printf("ERROR");
        exit(1);
    }
    *stage++;
    return true;
}

#endif