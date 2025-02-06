#include <stdio.h>

typedef char List;

int main()
{
    List a = 66; //0b1000001
    // printf("%d\n", a);
    // printf("%d", a & 0b01);

    switch (a & 0b11)
    {
    case 0b0:
        printf("Last 2 bit is 00");
        break;
    case 0b1:
        printf("Last 2 bit is 01");
        break;
    case 0b11:
        printf("Last 2 bit is 11");
        break;
    case 0b10:
        printf("Last 2 bit is 10");
        break;
    }
}