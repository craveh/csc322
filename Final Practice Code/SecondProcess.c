//-----------------------------
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//-----------------------------
int main(){
    int ChildPID;

    if((ChildPID = fork()) == -1){
        perror("Could not fork and run the child process");
        exit(1);
    }

    if(ChildPID == 0){
        printf("The childs PID is %d and the user name is %d\n", getpid(), getuid());
    }else{
        sleep(5);
        printf("The parents PID is %d and the user name is %d\n", getpid(), getuid());
    }


}
