#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

COORD coord={0,0};

int flipTiles(int num);
void drawTiles(int x, int y, int tiles, int selected, int selectCheck);
void gotoxy(int x,int y);

int main(){
	int fieldSize, i, r, control, checkPos = 1, currentPos = 1, x, y, selectCheck = 1, move = 0;
	int tiles[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	srand(time(NULL));
	do {
		for(i = 1; i <= 9; i++){
			r = rand() % 3;
			switch(r){
				case 1 :
					tiles[i] = 1;
					break;
				case 0 :
					tiles[i] = 0;
					break;
				case 2 :
					tiles[i] = 0;
					break;
			}
		}
	} while(tiles[1]+tiles[2]+tiles[3]+tiles[4]+tiles[5]+tiles[6]+tiles[7]+tiles[8]+tiles[9] != 2);


	do { // game clear
		
		do { // pressed enter
			
			system("cls");
			
			x = 10; y = 5; selectCheck = 1;
			drawTiles(x, y, tiles[1], currentPos, selectCheck);
			x = 18; y = 5; selectCheck++;
			drawTiles(x, y, tiles[2], currentPos, selectCheck);
			x = 26; y = 5; selectCheck++;
			drawTiles(x, y, tiles[3], currentPos, selectCheck);			
			x = 10; y = 10; selectCheck++;
			drawTiles(x, y, tiles[4], currentPos, selectCheck);
			x = 18; y = 10; selectCheck++;
			drawTiles(x, y, tiles[5], currentPos, selectCheck);			
			x = 26; y = 10; selectCheck++;
			drawTiles(x, y, tiles[6], currentPos, selectCheck);			
			x = 10; y = 15; selectCheck++;
			drawTiles(x, y, tiles[7], currentPos, selectCheck);
			x = 18; y = 15; selectCheck++;
			drawTiles(x, y, tiles[8], currentPos, selectCheck);			
			x = 26; y = 15; selectCheck++;
			drawTiles(x, y, tiles[9], currentPos, selectCheck);	
					
			printf("\n\n Your move: %d", move);
			
			control = getch();
			switch(control){
				case 'w' :
					checkPos -= 3;
					break;
				case 'a' :
					checkPos -= 1;
					break;
				case 's' :
					checkPos += 3;
					break;
				case 'd' :
					checkPos += 1;
					break;
			}
		
			if(checkPos > 0 && checkPos < 10){
				currentPos = checkPos;
			} else {
				checkPos = currentPos;
			}
			
		} while(control != 13);
			move++;
			switch(currentPos){
			case 1 :
				tiles[1] = flipTiles(tiles[1]);
				tiles[2] = flipTiles(tiles[2]);
				tiles[4] = flipTiles(tiles[4]);
				break;
			case 2 :
				tiles[2] = flipTiles(tiles[2]);
				tiles[1] = flipTiles(tiles[1]);
				tiles[3] = flipTiles(tiles[3]);
				tiles[5] = flipTiles(tiles[5]);
				break;		
			case 3 :
				tiles[3] = flipTiles(tiles[3]);
				tiles[2] = flipTiles(tiles[2]);
				tiles[6] = flipTiles(tiles[6]);
				break;		
			case 4 :
				tiles[4] = flipTiles(tiles[4]);
				tiles[1] = flipTiles(tiles[1]);
				tiles[5] = flipTiles(tiles[5]);
				tiles[7] = flipTiles(tiles[7]);
				break;
			case 5 :
				tiles[5] = flipTiles(tiles[5]);
				tiles[2] = flipTiles(tiles[2]);
				tiles[4] = flipTiles(tiles[4]);
				tiles[6] = flipTiles(tiles[6]);
				tiles[8] = flipTiles(tiles[8]);
				break;
			case 6 :
				tiles[6] = flipTiles(tiles[6]);
				tiles[3] = flipTiles(tiles[3]);
				tiles[5] = flipTiles(tiles[5]);		
				tiles[9] = flipTiles(tiles[9]);
				break;	
			case 7 :
				tiles[7] = flipTiles(tiles[7]);
				tiles[4] = flipTiles(tiles[4]);
				tiles[8] = flipTiles(tiles[8]);
				break;
			case 8 :
				tiles[8] = flipTiles(tiles[8]);
				tiles[5] = flipTiles(tiles[5]);
				tiles[7] = flipTiles(tiles[7]);
				tiles[9] = flipTiles(tiles[9]);
				break;
			case 9 :
				tiles[9] = flipTiles(tiles[9]);
				tiles[6] = flipTiles(tiles[6]);
				tiles[8] = flipTiles(tiles[8]);
				break;
			}
	} while(tiles[1]+tiles[2]+tiles[3]+tiles[4]+tiles[5]+tiles[6]+tiles[7]+tiles[8]+tiles[9] != 9);
	
	system("cls");
			x = 10; y = 5; selectCheck = 1;
			drawTiles(x, y, tiles[1], currentPos, selectCheck);
			x = 18; y = 5; selectCheck++;
			drawTiles(x, y, tiles[2], currentPos, selectCheck);
			x = 26; y = 5; selectCheck++;
			drawTiles(x, y, tiles[3], currentPos, selectCheck);			
			x = 10; y = 10; selectCheck++;
			drawTiles(x, y, tiles[4], currentPos, selectCheck);
			x = 18; y = 10; selectCheck++;
			drawTiles(x, y, tiles[5], currentPos, selectCheck);			
			x = 26; y = 10; selectCheck++;
			drawTiles(x, y, tiles[6], currentPos, selectCheck);			
			x = 10; y = 15; selectCheck++;
			drawTiles(x, y, tiles[7], currentPos, selectCheck);
			x = 18; y = 15; selectCheck++;
			drawTiles(x, y, tiles[8], currentPos, selectCheck);			
			x = 26; y = 15; selectCheck++;
			drawTiles(x, y, tiles[9], currentPos, selectCheck);	
	printf("\n\nGame Clear!!\nYou complete the game with [%d] move", move);
	getch();
}

int flipTiles(int num){
	if(num == 1){
		return 0;
	} else {
		return 1;
	}
}

void drawTiles(int x, int y, int tiles, int selected, int selectCheck){
	if(selected == selectCheck){
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 187);
		gotoxy(x, y+1);
		printf("%c      %c", 186, 186);
		gotoxy(x, y+2);
		printf("%c      %c", 186, 186);
		gotoxy(x, y+3);
		printf("%c      %c", 186, 186);
		gotoxy(x, y+4);
		printf("%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 188);
	} else {
		gotoxy(x, y);
		printf("%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 191);
		gotoxy(x, y+1);
		printf("%c      %c", 179, 179);
		gotoxy(x, y+2);
		printf("%c      %c", 179, 179);
		gotoxy(x, y+3);
		printf("%c      %c", 179, 179);
		gotoxy(x, y+4);
		printf("%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 217);
	}
	
	if(tiles == 1){
		gotoxy(x+1, y+1);
		printf("%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176);
		gotoxy(x+1, y+2);
		printf("%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176);
		gotoxy(x+1, y+3);
		printf("%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176);
		gotoxy(x+1, y+4);
	}
	
}

void gotoxy(int x,int y){ 
  	coord.X=x; 
 	coord.Y=y; 
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
} 