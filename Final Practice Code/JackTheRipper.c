//-----------------------------
#include <stdlib.h>
#include <stdio.h>


typedef struct {
   int Counter;
   float Average;
} hit_rate_type;
typedef struct {
    char *Name;
    hit_rate_type Killer;
    } murder_type;
typedef murder_type *JackTheRipper;



//-----------------------------
int main(){
    JackTheRipper person = (JackTheRipper) malloc(sizeof(murder_type));

    //strcpy(person ->Name, "Jack the Ripper");
    person -> Name = "Jack The Ripper";
    person -> Killer.Counter = 99;

    printf("%s,  %d", person ->Name, person -> Killer.Counter);



    free(person);


}



