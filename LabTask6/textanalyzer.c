//--------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef char String[256];
//---------------------
int GetNumOfCharacters(String line){
    int NumChars = 0;

    for(int i=0; i<strlen(line); i++){
        if(line[i] != '\0'){
            NumChars++;
        }else{
            break;
        }
    }
    return NumChars;
}
//-------------------------
 void OutputWithoutWhitespace(String line){
    String noWhitespace;

    int i, j;
    i =j =0;

    while(line[i] != '\0'){
        if(line[i] != '\t' && line[i] != ' '){
            noWhitespace[j] = line[i];
            i++;
            j++;
        }else{
            i++;
        }
    }
    noWhitespace[j] = '\0';
    printf("String with no whitespace: %s", noWhitespace);

}
//--------------------------
int main(){
    String sentence;
    printf("Enter a sentence or phrase: ");
    fgets(sentence, 256, stdin);

    printf("You entered: %s", sentence);

    int numChars = GetNumOfCharacters(sentence);
    printf("Number of characters: %d\n", numChars);

    OutputWithoutWhitespace(sentence);


}
//-------------------------
