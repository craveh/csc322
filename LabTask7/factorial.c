//-------------------
#include <stdlib.h>
#include <stdio.h>

//-----------------------

void calcFactorial(int *factorialPointer){

    int counter = *factorialPointer - 1;
    //printf("%d\n", counter);

    while(counter >= 1){
        *factorialPointer = ((*factorialPointer)*counter);
        counter--;

    }
    //printf("%d\n", *factorialPointer);

}


int main(void){

    int factorial, number;
    printf("Enter a number: ");
    scanf("%d", &factorial);
    printf("\n");
    number = factorial;

    calcFactorial(&factorial);

    printf("The factorial of %d is %d.\n", number, factorial);



}
