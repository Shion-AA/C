#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

typedef struct{
	int hp;
	int atk;
	float def;
	float luck;
	float critDmg;
	int money;
	int level;
	int exp;
}pStats;

bool chooseRole(pStats*);
void clearInputBuffer();
int randValue(int, int);

#endif