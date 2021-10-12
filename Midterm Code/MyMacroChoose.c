//---------------------
#include <stdlib.h>
#include <stdio.h>

#define LARGE


#ifdef LARGE
#define CHOOSE(A,B) (A)>(B)?(A):(B)
#else
#define CHOOSE(A,B) (A)<(B)?(A):(B)
#endif

//--------------------
int main(){
    int A = 3;
    int B = 2;

#ifndef LARGE
    printf("Smaller one is %d", CHOOSE(A,B));
#else
    printf("Larger one is %d", CHOOSE(A,B));
#endif // LARGE
}
