#include <stdio.h>
#include <stdlib.h>

void main(){
    // VERSION_1
    // unsigned int x = 8172386;
    // int i ,temp;
    // for(i = 1, temp = x; x != 1; x=x>>1, i=i<<1){}
    // // temp = 19, x = 1, i = 16
    // while(i != 0){
    //     if(temp >= i){
    //         printf("1");
    //         temp = temp - i;
    //         i = i >> 1;
    //     } else {
    //         printf("0");
    //         i = i >> 1;
    //     }
    // }

    // VERSION_2
    
}

int return8Ndigit(char str[], int i){
    
}

int my_strlen(char str[]){
	int count = 0;
	while(str[count] != '\0'){
		count++;
	}
	return count;
}

void my_strcpy(char dest[], char str[]){
	int i = 0;
	while(str[i] != '\0'){
		dest[i] = str[i];
		i++;
	}
}