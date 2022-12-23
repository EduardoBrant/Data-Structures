#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node *next;
}*stnode;

void createNodeList(int n);
void invertList();
void printList();

int main(){
    int n;

    printf("\n-------------------------------------------------");
    printf("\n                   Linked List                 \n");
    printf("\n-------------------------------------------------");
    
    printf("\nEnter the number of nodes you want to insert: ");
    scanf("%d", &n);
    printf("\n");

    createNodeList(n);

    printf("\nlist in order \n");
    printList();

    printf("\ninverted list \n");
    invertList();
    printList();

    return 0;
}

void createNodeList(int n){
    struct node *fnNode, *tmp;
    int num;

    stnode = (struct node*)malloc(sizeof(struct node));

    if(stnode == NULL){
        printf("\nMemory cannot be allocated !!");
    }else{
        printf("Insert the data of the 1° node: ");
        scanf("%d", &num);
        stnode -> num = num;
        stnode -> next = NULL;
        tmp = stnode;

        for (int i = 1 ; i < n; i++)
        {
            fnNode = (struct node*)malloc(sizeof(struct node));

            if(fnNode == NULL){
                printf("\nMemory cannot be allocated !!");
                break;
            }else{
                printf("Insert the data of the %i° node: ", i+1);
                scanf("%d", &num);
                fnNode -> num = num;
                fnNode -> next = NULL;
                tmp -> next = fnNode;
                tmp = tmp -> next;
            }
        }
    }
}

void invertList(){
    struct node *ltNode, *ctNode;

    if(stnode != NULL){
        ltNode = stnode;
        ctNode = stnode -> next;
        stnode = stnode -> next;

        ltNode -> next = NULL;

        while(stnode != NULL){
            stnode = stnode -> next;
            ctNode -> next = ltNode;

            ltNode = ctNode;
            ctNode = stnode;
        }

        stnode = ltNode;
    }
}

void printList(){
    struct node *tmp;

    if(stnode == NULL){
        printf("\nEmpty list");
    }else{
        tmp = stnode;
        
        int i = 1;
        while (tmp != NULL)
        {
            printf("%i° node data: %i \n", i,  tmp -> num);
            tmp = tmp -> next;
            i++;
        }
        printf("\n");
    }
}