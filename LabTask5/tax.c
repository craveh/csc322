#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//------------
char CalcTaxGroup(float TaxableIncome){
    char Group;

    if(TaxableIncome >= 500000){
        Group = 'S';
    }else if(TaxableIncome >=200000){
        Group = 'Q';
    }else if(TaxableIncome >=100000){
        Group = 'M';
    }else if(TaxableIncome >=50000){
        Group = 'A';
    }else if(TaxableIncome >=20000){
        Group = 'R';
    }else{
        Group = 'P';
    }

    return Group;
}
//------------
float ComputeTax(char Group, float TaxableIncome){
    float TaxRate, Tax;

    switch(Group){
        case 'S' :
        case 'Q' :
            TaxRate = 0.25;
            break;
        case 'M' :
            TaxRate = 0.10;
            break;
        case 'A' :
        case 'R' :
            TaxRate = 0.3;
            break;
        case 'P' :
            TaxRate = 0.0;
            break;
        default :
            printf("Error has occurred \n");
            break;
    }

    Tax = TaxableIncome*TaxRate;

    if(Tax > 50000){
        Tax = 50000;
    }
    return Tax;

}
//------------
int main(void){
    float Income, Deductions, Amount;
    Income = Deductions = 0;

    printf("%-17s: ", "Enter amount");
    scanf("%f", &Amount);

    while( (int)Amount != 0){
        if(Amount > 0){
            Income += Amount;
        }else{
            Deductions += abs(Amount);
        }

        printf("Enter next amount: ");
        scanf("%f", &Amount);
    }

    printf("\n%-14s: $%.2f\n","Income" ,Income);
    printf("%-14s: $%.2f\n","Deductions" ,Deductions);

    float TaxableIncome = Income - Deductions;
    if(TaxableIncome < 0){
        TaxableIncome = 0;
    }
    printf("Taxable income: $%.2f\n", TaxableIncome);

    char TaxGroup = CalcTaxGroup(TaxableIncome);
    printf("%-14s: %c\n","Tax group",TaxGroup);

    float Tax = ComputeTax(TaxGroup, TaxableIncome);
    printf("%-14s: $%.2f \n","Tax owed", Tax);

}
