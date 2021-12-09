//-----------------------------
#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 128
typedef char String[MAX_LENGTH];
typedef String *StringPointer;
//-----------------------------
int main(){

    char **arrayCharPointers[10];
    StringPointer pointer;
    String input;

    for (int i=0; i<10; i++){
        fgets(input, MAX_LENGTH, stdin);
        input[strlen(input) -1] = '\0';
        arrayCharPointers[i] = (char *) malloc(strlen(input)*sizeof(char));
        strcpy(arrayCharPointers[i], input);


    }
    for( int i =0; i<10; i++){
        printf("%s\n", arrayCharPointers[i]);
    }



    for( int i =0; i<10; i++){
        free((void *)arrayCharPointers[i]);
    }



}
