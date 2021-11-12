//---------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 128

typedef enum {mammal, insect, bird, fish, error} SpeciesType;
typedef char String[MAX];

typedef struct{
    String name;
    float size;
    SpeciesType species;

}Animal;
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
int setSpeciesType(String type){


    if(!strcasecmp(type,"mammal")){
        return mammal;
    }else if(!strcasecmp(type, "insect")){
        return insect;
    }else if(!strcasecmp(type, "bird")){
        return bird;
    }else if(!strcasecmp(type, "fish")){
        return fish;
    }else{
        return error;
    }


}
//----------------------------------
Animal createNewAnimal(String name){
    Animal newAnimal;
    float size;
    String type;

    //newAnimal.name = name;
    strcpy(newAnimal.name, name);
    printf("What is the size : ");
    scanf("%f", &size);
    newAnimal.size = size;
    printf("What is the type : ");
    scanf("%s", type);
    newAnimal.species = setSpeciesType(type);


    return newAnimal;


}

//--------------------------------
char* getAnimalType(SpeciesType species){
    switch(species){

        case mammal:
            return("mammal");
            break;
        case insect:
            return("insect");
            break;
        case bird:
            return("bird");
            break;
        case fish:
            return("fish");
            break;
        default:
            return("error");
            break;

    }


}


//----------------------------
void printInfo(Animal animal){
    String name;
    float size;
    String type;

    strcpy(name, animal.name);
    size = animal.size;
    //char* tpe = getAnimalType(animal.species);

    //type = getAnimalType(animal.species);


    printf("%-24s has size %6.2f and is a %s\n", name, size, getAnimalType(animal.species));


}

//---------------------------------
int main(void){
    Animal *animals;
    int numAnimals = 0;
    int arrayLength = 1;
    //Animal newAnimal;
    String name;

    printf("Enter animal information (\"exit\" to exit)\n");
    printf("What is the name : ");
    scanf("%s", name);


    //input all the species information
    while(strcasecmp(name, "exit")){ //while name != error
        //printf("%s\n", name);
        if(numAnimals == 0){
            animals = (Animal *)Malloc(sizeof(Animal));
            animals[numAnimals] = createNewAnimal(name);
            numAnimals++;

        }else{
            if(numAnimals == arrayLength){
                arrayLength *= 2;
                animals = (Animal *)realloc(animals, arrayLength*sizeof(Animal));
            }
            animals[numAnimals] = createNewAnimal(name);
            numAnimals++;
        }
        printf("Enter animal information (\"exit\" to exit)\n");
        printf("What is the name : ");
        scanf("%s", name);
    }

    //output info
    printf("\nThe following new species were found:\n");
    for(int i=0; i<numAnimals; i++){
        printInfo(animals[i]);
    }


    //free space
    free(animals);








}
