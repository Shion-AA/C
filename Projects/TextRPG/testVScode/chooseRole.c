#ifndef CHOOSEROLE_C
#define CHOOSEROLE_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#include "header.h"
#include "basicFunctions.c"

bool chooseRole(pStats * player)
{
    char inp;
    bool valid = true; //validation later

    printf("\nFirst, choose your role\n(1) Warrior\n(2) Mage\n(3) Tank\n");
    scanf(" %c", &inp);
    clearInputBuffer();
    system("cls");

    switch (inp)
    { // Choose Role
    case '1':
    case 'w':
    case 'W':
        player->hp = 100;
        player->atk = 30;
        player->def = 0.8;
        // def2 = 10;
        printf("You have chosen Warrior! Balanced in HP and ATK!!\n HP:%d ATK:%d DEF:%.2f\n", player->hp, player->atk, (1 - player->def) * 100);
        break;
    case '2':
    case 'm':
    case 'M':
        player->hp = 60;
        player->atk = 60;
        player->def = 0.94;
        // def2 = 3;
        printf("You have chosen Mage! High ATK but fragile...!\n HP:%d ATK:%d DEF:%.2f\n", player->hp, player->atk, (1 - player->def) * 100);
        break;
    case '3':
    case 't':
    case 'T':
        player->hp = 120;
        player->atk = 15;
        player->def = 0.6;
        // def2 = 20;
        printf("You chosen Tank! High sustain, low ATK!\n HP:%d ATK:%d DEF:%.2f\n", player->hp, player->atk, (1 - player->def) * 100);
        break;
    default:
        printf("ERROR");
        chooseRole(player);
    }

    return valid;
}

#endif