//---------------
#include <stdio.h>
#include <stdlib.h>

//----------------
float CalcAmbientPressure(int Depth){
    int FeetPerAtm = 33;
    float AmbientPressure = (Depth / FeetPerAtm) + 1;

    printf("%-16s: %.1f\n","Ambient Pressure", AmbientPressure);

    return AmbientPressure;
}
//--------------------
float CalcOxygenPressure(int Oxygen, float AmbientPressure){
    float Pressure = (Oxygen/100.0)*AmbientPressure;
    printf("%-16s: %.2f\n","Oxygen Pressure", Pressure);

    return Pressure;

}
//---------------------
void CalcOxygenGroup(float OxygenPressure){
    int Offset = (int)(OxygenPressure *10);
    char Group = Offset + 'A';
    printf("%-16s: %c\n", "Oxygen Group", Group);

}
//-------------------
int main(void){
    int Depth, OxygenPercent;
    float AmbientPressure, OxygenPressure;

    printf("%-30s: ", "Enter the depth");
    scanf("%d", &Depth);
    printf("Enter the percentage of oxygen: ");
    scanf("%d", &OxygenPercent);

    printf("\n");

    AmbientPressure= CalcAmbientPressure(Depth);

    OxygenPressure = CalcOxygenPressure(OxygenPercent, AmbientPressure);

    CalcOxygenGroup(OxygenPressure);


    printf("\n");
    printf("%-35s: ", "Exceeds maximal oxygen pressure");

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
