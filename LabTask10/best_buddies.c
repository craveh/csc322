//---------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 128

typedef char String[MAX];

typedef struct Node{
    String name;
    struct Node *next;
    struct Node *bestie;

} NodeType;

typedef NodeType *NodeTypePointer;

//--------------------------------------------------------------
NodeTypePointer getBestieNode(NodeTypePointer head, String bestieName, int counter){
    NodeTypePointer headStorer = head;
    NodeTypePointer copy;
    //printf("Test\n");

    for(int i=0; i<counter; i++){
        copy = head;
        if(!strcasecmp(copy->name, bestieName)){
            head = headStorer;
            return copy;
        }
        head = head ->next;
    }
    return NULL;

}

//--------------------------------------------------------------
void enterBestieInfo(NodeTypePointer head, int counter){
    NodeTypePointer headStorer = head;
    //NodeTypePointer nextNode;
    int thisCounter;
    String bestieName;


    while (thisCounter != counter) {
        printf("Enter the best friend of %s: ",head->name);
        scanf("%s", bestieName);
        head->bestie = getBestieNode(headStorer, bestieName, counter);


        //nextNode = head;
        head = head->next;
        thisCounter++;
    }
    head = headStorer;


}
//--------------------------------------------------------------
void printNodeInfo(NodeTypePointer head, int counter){
    NodeTypePointer headStorer = head;
    //NodeTypePointer nextNode;
    int thisCounter = 0;
    printf("\n");


    while (thisCounter != counter) {
        printf("%s's best friend is %s\n",head->name, head->bestie->name);
        //nextNode = head;
        head = head->next;
        thisCounter++;
    }
    head = headStorer;


}
//-----------------------------------------------------------------
void freeMemory(NodeTypePointer head){
    NodeTypePointer nextNode;

    while(head != NULL){
        nextNode = head;
        head = head->next;
        free(nextNode);
   }
}



//---------------------------------------------------------------
int main(){
    NodeTypePointer head = NULL;
    NodeTypePointer newNode;
    int nodeCounter = 0;

    String name;

    printf("Enter name (exit to exit): ");
    scanf("%s", name);
    while(strcasecmp(name,"exit")){
        newNode = (NodeTypePointer) malloc(sizeof(NodeType));
        strcpy(newNode->name, name);
        newNode->next = head;
        head = newNode;
        nodeCounter++;

        printf("Enter name (exit to exit): ");
        scanf("%s", name);
    }
    printf("\n");

    enterBestieInfo(head, nodeCounter);
    //printf("%s   %d %s\n ", head->name, nodeCounter, head->bestie->name);

    printNodeInfo(head, nodeCounter);

    freeMemory(head);



}

//---------------------------------------------------------------

