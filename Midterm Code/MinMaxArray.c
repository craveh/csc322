//--------------
#include <stdio.h>
#include <stdio.h>
//----------------

int main(){

    int arr[10];

    int i=0;
    while(i<10){
        printf("\nEnter a number into the array: ");
        scanf("%d", &arr[i]);
        i++;
    }
    int min, max;
    min = max =arr[0];
    for(i = 1; i<10; i++){
        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }
    printf("\nMin: %d\nMax: %d", min, max);

}
