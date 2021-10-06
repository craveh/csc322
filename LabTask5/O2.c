//---------------
#include <stdio.h>
#include <stdlib.h>

//----------------
float CalcAmbientPressure(int Depth){
    int FeetPerAtm = 33;
    float AmbientPressure = (Depth / FeetPerAtm) + 1;

    printf("Ambient Pressure: %.1f\n", AmbientPressure);

    return AmbientPressure;
}
//--------------------
float CalcOxygenPressure(int Oxygen, float AmbientPressure){
    float Pressure = (Oxygen/100.0)*AmbientPressure;
    printf("Oxygen Pressure: %.2f\n", Pressure);

    return Pressure;

}
//---------------------
void CalcOxygenGroup(float OxygenPressure){
    int Offset = (int)(OxygenPressure *10);
    char Group = Offset + 'A';
    printf("Oxygen Group: %c\n", Group);

}
//-------------------
int main(void){
    int Depth, OxygenPercent;
    float AmbientPressure, OxygenPressure;

    printf("Enter the depth: ");
    scanf("%d", &Depth);
    printf("Enter the percentage of oxygen: ");
    scanf("%d", &OxygenPercent);

    printf("\n");

    AmbientPressure= CalcAmbientPressure(Depth);

    OxygenPressure = CalcOxygenPressure(OxygenPercent, AmbientPressure);

    CalcOxygenGroup(OxygenPressure);


    printf("\n");
    printf("Exceeds maximal oxygen pressure: ");

    if(OxygenPressure > 1.4){
        printf("true\n");
    }else{
        printf("false\n");
    }

    printf("Exceeds contingency oxygen pressure: ");

    if(OxygenPressure > 1.6){
        printf("true\n");
    }else{
        printf("false\n");
    }

}
