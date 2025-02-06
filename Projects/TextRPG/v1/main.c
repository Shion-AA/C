#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
    int main(){
    	char enemy[][15] = {"???", "SLIME", "GOBLIN", "ORC", "CYCLOPS", "DRAGON", "GOLDEN SLIME"};
    	char move[30][8] = {"Tackle", "Slam", "Punch"};
    	int hp[100]  = {0, 44, 39, 49, 75, 125, 999};
    	int atk[100] = {0, 5,  12, 8,  15,  30,  1};
    	float def[100] = {1, 1,  1,  0.95,  0.9,  0.8,  0.01};
   		int stage, def2, dice, rng, dmg, exp, coin, check = 0;
    	char inp;
    	srand(time(0));
    	printf("Welcome to the Text-based RPG!!");
    	printf("\nFirst, choose your role\n(1) Warrior\n(2) Mage\n(3) Tank\n");
    	scanf(" %c", &inp);
    	fflush(stdin);
    	system("cls");
    
        switch(inp){ //Choose Role
            case '1':
            case 'w':
            case 'W':
                hp[0] = 100;
                atk[0] = 30;
                def[0] = 0.8;
                def2 = 10;
                printf("You have chosen Warrior! Balanced in HP and ATK!!\n HP:%d ATK:%d DEF:20\n", hp[0], atk[0]);
                break;
            case '2':
            case 'm':
            case 'M':
                hp[0] = 60;
                atk[0] = 60;
                def[0] = 0.94;
                def2 = 3;
                printf("You have chosen Mage! High ATK but fragile...!\n HP:%d ATK:%d DEF:6\n", hp[0], atk[0]);
                break;
            case '3':
            case 't':
            case 'T':
                hp[0] = 120;
                atk[0] = 15;
                def[0] = 0.6;
                def2 = 20;
                printf("You chosen Tank! High sustain, low ATK!\n HP:%d ATK:%d DEF:40\n", hp[0], atk[0]);
                break;
            default:
                printf("ERROR");
                exit(1);
        }
    Sleep(1500);
    printf("\nThe adventure begins!!!!\n");
    Sleep(1500);
    printf("\nFirst floor...You see 3 ways ahead...\nThe route: \n(1) Left\n(2) Center\n(3) Right\n");
    scanf(" %c", &inp);
    fflush(stdin);
    system("cls");
    switch (inp){ //Choose 1,2,3 path
        case'1':
        case'l':
        case'L':
            printf("You have chosen the LEFT path");
            rng = rand()%3 + 1;
    		break;
        case'2':
        case'c':
        case'C':
            printf("You have chosen the CENTER path");
            break;
        case'3':
        case'r':
        case'R':
        	printf("You have chosen the RIGHT path");
            break;
		default:
            printf("ERROR");
            exit(1);
    }
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf("..");
		Sleep(1000);
		printf("...");
		Sleep(1000);
		system("cls");
		
    	hp[rng] += (rand() % 7);
    	//printf("%d %d", hp[0], hp[1]);
    	printf("The %s has appeared!!", enemy[rng]);
    	while(hp[rng]>0 && hp[0]>0){
    		printf("\n%s HP : %d           Your HP : %d", enemy[rng], hp[rng], hp[0]);
    		printf("\n(1) Attack       (3) Item\n(2) Defend       (4) Run\n");
    		scanf("%[^\n]c", &inp);
    		fflush(stdin);
    		system("cls");
    		switch(inp){ //User Choice
    			case '1':
				case 'a':
				case 'A':
					printf("You rolled a dice...");
					dice = rand()%6+1;
					Sleep(1000);
					switch(dice){ //user attack
						case 1:
							dmg = 0;
							dmg *= def[rng];
							hp[rng] -= dmg;
							printf("1!!\nYou missed the attack...");
							break;
						case 2 ... 5:
							dmg = atk[0] + dice;
							dmg *= def[rng];
							hp[rng] -= dmg;
							printf("%d!! You dealt %d Damage!!", dice, dmg);
							break;
						case 6:
							dmg = (atk[0] + 6) * 2;
							dmg *= def[rng];
							hp[rng] -= dmg;
							printf("6!! CRITICAL HIT!!\nYou dealt %d Damage!!", dmg);
							break;
					}
					break;
				case '2':
				case 'd':
				case 'D':
					printf("You prepared to defend enemy attack");
					break;
				case '3':
				case 'i':
				case 'I':
					printf("You have no Item...");
					break;
				case '4':
				case 'r':
				case 'R':
					printf("You can't run...");
					break;
				default:
					printf("H U H ?");
					break;
			}
			if ((hp[rng]>0) && (inp == '2' || inp == 'd' || inp == 'D' || inp == '1' || inp == 'a' || inp == 'A')){
				dmg *= def[0];
				printf("\nEnemy attack!!");
				if (inp == '2' || inp == 'd' || inp == 'D'){
					dmg *= def[0] - def2;
					printf("You defended yourself!");
				}
				if (dmg < 1){
					dmg = 1;
				}
				printf("\nYou took %d damage...", dmg);
				hp[0] -= dmg;
			}
		}
			if (hp[0]<0){
			printf("You died...");
			return 0;
		} else if (hp[rng]<0){
			printf("\n\nYou defeated %s!!\nCoins +9999999\n", enemy[rng]);
			stage += 1;
		}
	system("pause");
	return 0;
	}