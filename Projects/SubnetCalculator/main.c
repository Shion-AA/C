#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cToBinary(int);
int cToDecimal(int);

typedef struct{
	int a, b, c, d, prefix, subA, subB, subC, subD;
}address;

typedef struct{
	char aBinary[8], bBinary[8], cBinary[8], dBinary[8], aSubBinary[8], bSubBinary[8], cSubBinary[8], dSubBinary[8];
}binaryAddress;

int main(){
	char addressStr[16], prefixStr[4];
	
	address originalAddress;
//	printf("%d", pow(2, 0));
	printf("Enter the original network address\nFormat:123.45.78.90\n");
	scanf("%s", addressStr);
	printf("Enter prefix: /");
	scanf(" %s", prefixStr);
	
	if (prefixStr[0] == '/'){
		originalAddress.prefix = atoi(prefixStr[1]);
	} else {
		originalAddress.prefix = atoi(prefixStr);
	}
	
	originalAddress.a = atoi(strtok(addressStr, "."));
	originalAddress.b = atoi(strtok(NULL, "."));
	originalAddress.c = atoi(strtok(NULL, "."));
	originalAddress.d = atoi(strtok(NULL, "."));
	
//	printf("%d is the prefix", originalAddress.prefix);
//	printf("\n%d.%d.%d.%d is the given address", originalAddress.a, originalAddress.b, originalAddress.c, originalAddress.d);

//	int i;
//	if(originalAddress.prefix > 30){
//		printf("too small host portion");
//		return 0;
//	} else if(originalAddress.prefix > 23){
//		originalAddress.subA = 255;
//		originalAddress.subB = 255;
//		originalAddress.subC = 255;
//		if(originalAddress.prefix%8== 0){
//			originalAddress.subD = 255;
//		} else {
//			originalAddress.subD = (256 - pow(2, (8 - originalAddress.prefix%8)));
//		}
//	} else if(originalAddress.prefix > 15){
//		originalAddress.subA = 255;
//		originalAddress.subB = 255;
//		if(originalAddress.prefix%8== 0){
//			originalAddress.subC = 255;
//		} else {
//			originalAddress.subC = (256 - pow(2, 8 - originalAddress.prefix%8));
//		}
//	} else if(originalAddress.prefix > 7){
//		originalAddress.subA = 255;
//		if(originalAddress.prefix%8== 0){
//			originalAddress.subB = 255;
//		} else {
//			originalAddress.subB = (256 - pow(2, 8 - originalAddress.prefix%8));
//		}
//	} else {
//		if(originalAddress.prefix%8== 0){
//			originalAddress.subA = 255;
//		} else {
//			originalAddress.subA = (256 - pow(2, 8 - originalAddress.prefix%8));
//		}
//	}

//	binaryAddress bAdd;
//	strcpy(bAdd.aBinary, itoa(cToBinary(originalAddress.a)));
//	itoa(cToBinary(originalAddress.a), bAdd.aBinary, 10);
//	printf("%s", bAdd.aBinary);
	
	
	int subnetSize, n, totalSize, adda, addb, addc, addd;
	printf("Enter the size of each subnet: "); //assume the user enters proper size such as 32, 64, 128, so on...
	scanf("%d", &subnetSize);
	printf("Enter n'th subnet you are looking for: ");
	scanf("%d", &n);
	totalSize = subnetSize * n;
	if(totalSize > pow(2, 24)){
		adda = totalSize / pow(2, 24);
		totalSize -= adda * pow(2, 24);
		originalAddress.a += adda;
	}
	if(totalSize > pow(2, 16)){
		addb = totalSize / pow(2, 16);
		totalSize -= addb * pow(2, 16);
		originalAddress.b += addb;
	}
	if(totalSize > pow(2, 8)){
		addc = totalSize / pow(2, 8);
		totalSize -= addc * pow(2, 8);
		originalAddress.c += addc;
	}
	originalAddress.d += totalSize;

	printf("\n\n\nAssuming all the information you entered is accurate:\nthe %d'th network address of the given subnet is %d.%d.%d.%d", n, originalAddress.a, originalAddress.b ,originalAddress.c, originalAddress.d);
	
}

int cToDecimal(int n) { //from internet cuz im too lazy
  int dec = 0, i = 0, rem;

  while (n != 0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  return dec;
}

int cToBinary(int n) {
  int bin = 0;
  int rem, i = 1;

  while (n != 0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }
  return bin;
}


