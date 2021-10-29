//----------------
#include <stdlib.h>
#include <stdio.h>

#define true  1
#define false 0

typedef char String[1024];
//-------------------

int main(void){

    char c, prev;
    int inComment, inString, possibleCommentStart,possibleCommentEnd;
    inComment= inString = possibleCommentStart = possibleCommentEnd = false;
    String comments;
    int index = 0;


    while((c = getchar()) != EOF){

        //printf("%c =, inString: %d, inComment: %d, possibleCommentstart: %d, possible end: %d\n", c, inString, inComment, possibleCommentStart, possibleCommentEnd);



          //Deals with the case, of when  in comment, we have a possible end, but next char is not /.
          if(!inString && inComment && possibleCommentEnd && c != '/'){
            comments[index++] = prev;
            possibleCommentEnd = false;
            //inComment = false;
            //printf("test\n  + %c", c);
          }



        switch(c){
        case '/':
            // Check that we are not in string or comment, comment might start
            if(!inString){

                if(!inComment){
                    possibleCommentStart = true;
                }else{
                    if(!possibleCommentEnd){
                    //Case of in a comment has a /, unrelated to end comment
                    comments[index++] = c;
                    }else{
                    //we are at the end of a comment
                    inComment = false;
                    possibleCommentEnd = false;
                    comments[index++] = '\n';
                    }
                }
            }

          break;
        case '*':
            if(!inString){
                if(possibleCommentStart && !inComment){
                    inComment = true;
                    possibleCommentStart = false;
                }else if(inComment && !possibleCommentEnd){
                    possibleCommentEnd = true;
                    prev = c;

                }
            }

            break;
        case '"':
            if(!inComment){
                if(!inString){
                    inString = true;
                }else{
                    inString = false;
                }
            }else{
                comments[index++] = c;
            }
            if(possibleCommentStart){
                possibleCommentStart = false;
            }

            break;
        case '\'':
            if(!inComment){
                if(!inString){
                    inString = true;
                }else{
                    inString = false;
                }
            }else{
                comments[index++] = c;
            }

            if(possibleCommentStart){
                possibleCommentStart = false;
            }

            break;

        default:
            if(inComment){
                comments[index++] = c;
            }
            if(possibleCommentStart){
                possibleCommentStart = false;
            }







        }



    }
    printf("The comments are:\n%s", comments);



}
