//-------------------------
#include <stdlib.h>
#include <stdio.h>

typedef int *intPointer;
typedef int Array[5];
typedef intPointer ArrayPointer[5];
//-------------------------------
void printArrNumbers(Array array){
    for(int i =0; i<5; i++){
        printf("%d  ", array[i]);
    }
    printf("\n\n");



}
//-------------------------
void printArrPointer(ArrayPointer arr){

    for(int i=0; i<5; i++){
        printf("%d  ", *arr[i]);
    }
    printf("\n\n");



}
//-------------------------
void sortPointers(ArrayPointer pointers){

    for(int i=0; i<4; i++){
        for(int j=0; j<4-i;j++){
            if(*(*(pointers +j) ) > *(*(pointers +j + 1))){
                intPointer temp = *(pointers + j);
                *(pointers +j) = *(pointers +j + 1);
                *(pointers + j+ 1) = temp;

            }
        }
    }


}

//---------------------------------
void sort(Array array){
    //int j=2;
    //printf("%d  %d \n", *(array + 3), *(array+ 3 + 1));
    for(int i=0; i<4; i++){
        for(int j=0; j<4-i;j++){

            if(*(array +j) > *(array +j +1)){
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j+ 1) = temp;
            }
        }
    }

}


//--------------------------
int main(void){
    Array numbers;
    ArrayPointer pointers;

    for(int i=0; i<5; i++){
        //numbers[i] = rand();
        numbers[i] = srand(getpid());
        pointers[i] = &numbers[i];
    }
    //print orginal int array
    printf("Initialized array of integers: \n");
    printArrNumbers(numbers);

    //sort the array of pointers and print
    sortPointers(pointers);
    printf("Sorted array of pointers: \n");
    printArrPointer(pointers);


    //sort number array and print numbers and pointer
    sort(numbers);
    printf("Sorted array of integers: \n");
    printArrNumbers(numbers);
    printf("Array of pointers: \n");
    printArrPointer(pointers);










}
//---------------------------
