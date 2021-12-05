//-------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256
#define MAX_COMMANDS 100
#define MAX_CHARS 81 //Add a char for '\0'

typedef char String[MAX_LENGTH];
typedef char TextType[2*MAX_CHARS]; //
typedef int RangeOfTwoNums[2];


typedef enum{
    none, text,lineNums
} LineRangeSpecificationTypes;

typedef union{
    TextType text;
    RangeOfTwoNums lineNumbersRange;
    int lineNumber;
} LineRangeInfo;



typedef struct{
    LineRangeSpecificationTypes lineRangeSpec;
    LineRangeInfo lineRangeInfo;
    char editCommand;
    TextType editText;
} CommandDetails;

typedef CommandDetails CommandsArray[MAX_COMMANDS];

//-------------------------------------
void PutInNullChar(char *line){
    if(line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = '\0';
    }
}

//-------------------------------------
int LoadEditCommandsFromFile(char *fileName, CommandsArray commands){
    FILE * CommandsFile;
    String input;
    int commandIndex = 0;
    char *start, *end;

    if((CommandsFile = fopen(fileName, "r"))== NULL){
        perror("Cannot open the commands file.\n");
        exit(1);
    }
    while(fgets(input,MAX_LENGTH, CommandsFile) !=NULL){
        PutInNullChar(input);
        start = input;
        if(isdigit(*start)){

        }else if(ispunct(*start)){
            printf("Testing %s", input);
        }else{
        }

    }
    return commandIndex;


}

//-------------------------------------



//-------------------------------------


//-------------------------------------
int main(int argc, char * argv[] ){
    CommandsArray commands;
    int numCommands;
    if(argc < 2){
        perror("Not enough arguements");
        exit(1);
    }
    numCommands = LoadEditCommandsFromFile(argv[1], commands);






}
//-------------------------------------
