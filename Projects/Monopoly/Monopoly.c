#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int tiles[41];
	int i, x;
	
	printf("How many player? ");
	scanf("%d", &x);
	fflush(stdin);
	
	int player[x];
	char pName[x];
	char pNameHolder[x];
	
	for(i = 1; i <= x; i++){
		printf("Enter name for player [%d]: ", i);
		scanf("%s", pNameHolder);
		pName[i] = pNameHolder;
	}
	
	printf("\n\n%s", pName[1]);
	
}







