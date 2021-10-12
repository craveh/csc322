//--------------------
#include <stdio.h>
#include <stdlib.h>

typedef char String[128];
//----------------------
int main(){
    String name, address;
    int age;
    printf("Enter your name, age and address: ");
    scanf("%s %d %s", name, &age, address);

    printf("\nYour name is %s, you are %d years old and live at %s.\n", name, age, address);

}
