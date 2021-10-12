//---------------------------
#include <stdlib.h>
#include <stdio.h>
//--------------------------
int main(void){
    int c;

    c = getchar();
    while(c != EOF){
        if(c == '\t'){
            printf("\\t");
        }else if(c == '\n'){
            printf("\\n\n");
        }else if(c == '\\'){
            printf("\\\\");
        }else{
            putchar(c);
        }
        c = getchar();

    }
}



