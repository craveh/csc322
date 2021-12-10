//-------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256
#define MAX_COMMANDS 100
#define MAX_CHARS 81

typedef char String[MAX_LENGTH];
typedef char TextType[2*MAX_CHARS];
typedef int RangeOfTwoNums[2];


typedef enum{
    none, text,lineNums
} LineRangeSpecificationTypes;

typedef union{
    TextType text;
    RangeOfTwoNums lineNumbersRange;
} LineRangeInfo;



typedef struct{
    LineRangeSpecificationTypes lineRangeSpec;
    LineRangeInfo lineRangeInfo;
    char editCommand;
    TextType editText;
} CommandDetails;

typedef CommandDetails CommandsArray[MAX_COMMANDS];

//-------------------------------------
/*Function to put the null char in at the end of string*/
void PutInNullChar(char *line){
    if(line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = '\0';
    }
}

//-------------------------------------
int LoadEditCommandsFromFile(char *fileName, CommandsArray commands){
    FILE * CommandsFile;
    String input;
    int numCommands = 0;
    char *start, *end;

    //try to open file
    if((CommandsFile = fopen(fileName, "r"))== NULL){
        perror("Cannot open the commands file.\n");
        exit(1);
    }
    //read and process commands stored in file
    while(fgets(input,MAX_LENGTH, CommandsFile) !=NULL){
        PutInNullChar(input);
        start = input;
        if(isdigit(*start)){
            commands[numCommands].lineRangeSpec = lineNums;
            end = strchr(start, ',');
            *end = '\0';
            commands[numCommands].lineRangeInfo.lineNumbersRange[0] = atoi(start);
            start = end + 1;
            end = strchr(start, '/');
            *end = '\0';

            commands[numCommands].lineRangeInfo.lineNumbersRange[1] = atoi(start);

            //start = end + 1;

            //printf("Testing\n");

            start = end + 1; //move 2 spots to get the edit operation
            //printf("%d,%d\n", commands[numCommands].lineRangeInfo.lineNumbersRange[0],commands[numCommands].lineRangeInfo.lineNumbersRange[1]);


        }else if(ispunct(*start)){
            commands[numCommands].lineRangeSpec = text;
            start++;
            end = strchr(start, '/');
            *end = '\0';
            strcpy(commands[numCommands].lineRangeInfo.text, start);
            start = end + 1;
        }else{
            commands[numCommands].lineRangeSpec = none;
        }
        commands[numCommands].editCommand = *start;
        start++;
        //printf("Command #%d:%c\n", numCommands, commands[numCommands].editCommand);
        strcpy(commands[numCommands].editText, start);
        numCommands++;

    }
    //printf("numCommands: %d\n", numCommands);
    //close file
    fclose(CommandsFile);
    return numCommands;


}

//-------------------------------------
/*A function that I used to debug my code, it tests if the commands were read properly*/
void TestCommandsInputted(CommandsArray commands, int numCommmands){
    for(int i =0; i<numCommmands;i++){
        switch(commands[i].lineRangeSpec){
            case none:
                printf("%c %s\n", commands[i].editCommand, commands[i].editText);
                break;
            case text:
                printf("%s Command:%c %s \n", commands[i].lineRangeInfo.text, commands[i].editCommand, commands[i].editText);
                break;
            case lineNums:
                printf("%d,%d %c %s\n", commands[i].lineRangeInfo.lineNumbersRange[0],commands[i].lineRangeInfo.lineNumbersRange[1], commands[i].editCommand, commands[i].editText);
                break;
            default:
                break;


        }
    }

}
//-----------------------------------------------------
/*Function I used to debug, prints the detail of 1 command*/
void PrintCommandDetails(CommandDetails command){
    printf("Line Range spec:");
    switch(command.lineRangeSpec){
        case none:
                printf("none. ");
                break;
            case text:
               printf("text. ");
                break;
            case lineNums:
                printf("lineNumbers. ");
                break;
            default:
                printf("error. ");
                break;
    }
    printf("The edit operation is:%c\n", command.editCommand);



}
//-------------------------------------
/*Makes edits to the user input*/
int editUserInput(String input,CommandDetails command){
    //printf("%c ", command.editCommand);
    //PrintCommandDetails(command);
    String temp, marker, copyEditText;
    char *search, *replace,*position;
    switch(command.editCommand){
        case 'A':
            strcat(input, command.editText);
            break;
        case 'I':
            strcpy(temp,command.editText);
            strcat(temp, input);
            strcpy(input, temp);
            break;
        case 'O':
            printf("%s\n",command.editText);
            break;
        case 'd':
            //printf("Testing 'd' command running");
            return(1);
            break;
        case 's':
            //printf("Testing if enter case 's'\n");

            marker[0] = command.editText[0];
            marker[1] = '\0';
            strcpy(copyEditText, &command.editText[1]);
            search = strtok(copyEditText, marker);
            replace = strtok(NULL, marker);
            while((position = strstr(input, search))!=NULL){
                strncpy(temp, input, position - input);
                temp[position - input] ='\0';
                strcat(temp, replace);
                strcat(temp, &input[(position - input) + strlen(search)]);
                strcpy(input, temp);
            }


            break;
        default:
            printf("Error with command type.\n");
            break;
    }
    //PrintEditedInput(command)
    return(0);


}
//-------------------------------------
/*Checks if edits should be done to this line of input*/
int CheckLineInRange(String line, int lineNumber, CommandDetails command){
    switch(command.lineRangeSpec){
        case none:
            return (1);
            break;
        case text:
            //printf("%s", command.lineRangeInfo.text)
            return (strstr(line, command.lineRangeInfo.text)!= NULL);
            break;
        case lineNums:
            return(lineNumber >= command.lineRangeInfo.lineNumbersRange[0] && lineNumber <= command.lineRangeInfo.lineNumbersRange[1]);
            break;
        default:
            printf("Error with checking if the line is in range");
            return 0;
            break;
    }

}

//-------------------------------------
int main(int argc, char * argv[] ){
    CommandsArray commands;
    int numCommands, currentNum, LineDeleted;
    String input;

    //check num args
    if(argc < 2){
        perror("Not enough arguments");
        exit(1);
    }
    //load commands
    numCommands = LoadEditCommandsFromFile(argv[1], commands);
    //TestCommandsInputted(commands, numCommands);
    //get user input and execute commands
    if(numCommands > 0){
        currentNum = 0;
        while(fgets(input, MAX_LENGTH, stdin)!= NULL){
            PutInNullChar(input);
            currentNum++;
            LineDeleted =0;
            for(int i=0; i<numCommands && !LineDeleted; i++){
                //printf("Command:%c\n", commands[i].editCommand);

                if(CheckLineInRange(input,currentNum, commands[i])){

                    //printf("Command:%c", commands[i].editCommand);
                    LineDeleted = editUserInput(input, commands[i]);
                }
            }
            if(!LineDeleted){
                printf("%s\n", input);
            }

        }

    }
    //TestCommandsInputted(commands, numCommands);
    return 0;





}
//-------------------------------------

