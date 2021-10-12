//----------------------------
#include <stdio.h>
#include <stdlib.h>

//----------------------------------
float Conversion(int Celcius){
    float Fahren;
    Fahren = (Celcius *(9.0/5)) + 32;
    return Fahren;
}
//
int main(void){
    int Celcius = 148;

    for(int i = Celcius; i >= -17; i-=8){
        printf("%4d Celcius is %5.1f Fahrenheight \n", i, Conversion(i));
    }









}
