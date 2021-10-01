//-----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------
float KangarooDensity(float Kangaroos, float Side){
  float Density = (Kangaroos / (pow(Side,2)));
  //  printf("Density %f \n", Density);
  return Density;
}

float RoadSurfaceAreaCalc(float RoadLength){
  float RoadWidth = 10; //in meter
  RoadWidth = RoadWidth * 0.001; //convert to km

  //printf("RoadWidth adj %f \n", RoadWidth);
  float SurfArea = RoadLength * RoadWidth;
  // printf("SurfaceArea %f \n", SurfArea);
  return SurfArea;
}

void OutputNumKills(float KangarooDensity, float RoadArea){
  float KillConstant = 1.47;
  float NumKilled = KangarooDensity * RoadArea * KillConstant;
  printf("\n\nThe expected number of kills is : %.1f \n", NumKilled);
}

int main(void){
  float Side, RoadLength, Kangaroos;
//get all the info needed
  printf("Enter the side of the square in km: ");
  scanf("%f", &Side);

  printf("Enter the road length in km: ");
  scanf("%f", &RoadLength);

  printf("Enter the number of Kangaroos: ");
  scanf("%f", &Kangaroos);

//do calcs
  float KangDensity = KangarooDensity(Kangaroos, Side);
  float SurfaceArea = RoadSurfaceAreaCalc(RoadLength);
  OutputNumKills(KangDensity, SurfaceArea);
