//--------------
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//-----------------
int main(){
    int a,b;

    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);

    int sum = a + b;
    float avg = (a+b)/2.0;
    int sumSquare = pow(a,2) + pow(b,2);

    printf("\nSum: %d\nAvg: %.2f\nSum of Squares: %d\n", sum, avg, sumSquare);
}
