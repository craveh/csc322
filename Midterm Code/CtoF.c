//-----------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------
float Conversion (float Celcius){
    float Fahren = (Celcius * (9.0/5)) + 32;
    return Fahren;

}
//-------------------------
int main(void){
    float Celcius;

    printf("Enter a number in celcius you'd like to convert: ");
    scanf("%f", &Celcius);

    printf("\n%.1f degrees Celcius converts to %.1f degrees Fahrenheit.\n", Celcius, Conversion(Celcius));


}
