//---------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 128


typedef char String[MAX];

typedef struct{
    String name;
    float price;
    int quantity;
    int totalPrice;

}Item;
//---------------------------------
void * Malloc(size_t Size) {

    void * Memory;

    if ((Memory = malloc(Size)) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    } else {
        return(Memory);
    }
}

//----------------------------------
Item createNewItem(String name){
    Item newItem;
    float price;
    int quantity;
    //String nothing;

    strcpy(newItem.name, name);
    //scanf("%s", nothing);
    printf("\n\tprice: ");
    scanf("%f", &price);
    newItem.price = price;
    printf("\n\tquantity: ");
    scanf("%d", &quantity);

    newItem.quantity = quantity;

    newItem.totalPrice = (int) quantity*price;

    return newItem;


}




//----------------------------
void printInfo(Item item){


    printf("\t  %-15s %d     $%d%\n\n",item.name, item.quantity, item.totalPrice);


}
//----------------------------------
void sort(Item *list, int numItems){

    for(int i=0; i<numItems; i++){
        for(int j=0; j<numItems-i;j++){

            if(list[j].totalPrice < list[j+1].totalPrice){
                Item temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

}
//---------------------------------
int main(void){
    Item *items;
    int numItems = 0;
    int arrayLength = 1;
    String name;



    printf("Enter item information (\"exit\" to exit)\n");
    printf("\n\tItem %d: ", numItems + 1);
    fgets(name, MAX, stdin);
    name[strlen(name)-1] = '\0';


    //get all the inputs
    while(strncasecmp("exit", name, 4)){ //while name != error
        //printf("%s\n", name);
        if(numItems == 0){
            items = (Item *)Malloc(sizeof(Item));
            items[numItems] = createNewItem(name);
            numItems++;


        }else{
            //printf("%d vs %d \n", numItems, arrayLength);
            if(numItems == arrayLength){
                arrayLength *= 2;
                items = (Item *)realloc(items, arrayLength*sizeof(Item));
                //printf("testing");

            }
            items[numItems] = createNewItem(name);
            numItems++;
        }

        printf("\nEnter item information (\"exit\" to exit)\n");
        printf("\n\tItem %d: ", numItems + 1);
        //printf("test");
        fgets(name, MAX, stdin);
        fgets(name, MAX, stdin);
        name[strlen(name)-1] = '\0';
        //printf("%s\n", name);
    }


    //sort the structs in order of total price of item
    sort(items, numItems);



    //output info
    int total =0;

    printf("\n\n\tYour List:\n\n");
    for(int i=0; i<numItems; i++){
        printInfo(items[i]);
        total += items[i].totalPrice;
    }
    printf("\t----------------------------\n");
    printf("\tTotal                    $%d\n", total);



    //free space
    free(items);



}

