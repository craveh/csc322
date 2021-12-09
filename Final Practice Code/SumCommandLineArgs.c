//-----------------------------
#include <stdlib.h>
#include <stdio.h>

//-----------------------------
int main(int argc, char *argv[]){

    if(argc <= 1){
        printf("Not enough arguments\n");
        exit(1);
    }
    int numIntsToSum = argc -1;
    int sum = 0;

    for(int i =1; i <= numIntsToSum; i++){
        sum += atoi(argv[i]);

    }
    //printf("The sum is %d\n", sum);
    return sum;


}
