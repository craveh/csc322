//-----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------
float WallAreaCalc(float Height, float Width){
  float Area = Height * Width;
  printf("Wall area: %.2f sq feet \n", Area);
  return Area;
}

float PaintNeededCalc(float WallArea){
  float Paint = WallArea/ 350;
  printf("Gallons of paint needed: %.2f gallons\n", Paint);

  return Paint;
}

void CalcPaintCans(float Gallons){

  int NumCans = ceil(Gallons);
  printf("Cans of paint needed: %d can(s)\n\n", NumCans);
}

int main(void){
  float Height, Width;
  //get all the info needed
  printf("Enter the height of the wall in feet: ");
  scanf("%f", &Height);

  printf("Enter the width of the wall in feet : ");
  scanf("%f", &Width);

  printf("\n");

  //do calcs
  float Area = WallAreaCalc(Height, Width);
  float Paint = PaintNeededCalc(Area);
  CalcPaintCans(Paint);
}

//--------------------------------------------------
