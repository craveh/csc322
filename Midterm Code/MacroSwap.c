//---------------------
#include <stdlib.h>
#include <stdio.h>

#define SWAP(t,A,B) { t newA = A; \
                        A = B; \
                        B = newA; }
//-----------------------------
int main(void)
{
    char x,y;
    x='a';
    y='b';
    printf("x= %c \t y= %c\n",x,y);
    SWAP(char,x,y);
    printf("x=%c \t y=%c\n",x,y);
}
