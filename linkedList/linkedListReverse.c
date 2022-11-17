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
    printf("\n cria uma lista ligada e amostra na ordem inversa");
    printf("\n-------------------------------------------------");
    
    printf("\n\nDigite o numero de nós que deseja inserir: ");
    scanf("%d", &n);
    printf("\n");

    createNodeList(n);

    printf("\nLista em ordem: \n");
    printList();

    printf("\nlista invertida : \n");
    invertList();
    printList();

    return 0;
}

void createNodeList(int n){
    struct node *fnNode, *tmp;
    int num;

    stnode = (struct node*)malloc(sizeof(struct node));

    if(stnode == NULL){
        printf("\n Memória não pode ser alocada ");
    }else{
        printf("Insira o dado do 1° nó: ");
        scanf("%d", &num);
        stnode -> num = num;
        stnode -> next = NULL;
        tmp = stnode;

        for (int i = 1 ; i < n; i++)
        {
            fnNode = (struct node*)malloc(sizeof(struct node));

            if(fnNode == NULL){
                printf("\n Memória não pode ser alocada ");
                break;
            }else{
                printf("Insira o dado do %i° nó: ", i+1);
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
    struct node *noAnterior, *noAtual;

    if(stnode != NULL){
        noAnterior = stnode;
        noAtual = stnode -> next;
        stnode = stnode -> next;

        noAnterior -> next = NULL;

        while(stnode != NULL){
            stnode = stnode -> next;
            noAtual -> next = noAnterior;

            noAnterior = noAtual;
            noAtual = stnode;
        }

        stnode = noAnterior;
    }
}

void printList(){
    struct node *tmp;

    if(stnode == NULL){
        printf("\nLista vazia");
    }else{
        tmp = stnode;
        
        int i = 1;
        while (tmp != NULL)
        {
            printf("Dado do %i° nó : %i \n", i,  tmp -> num);
            tmp = tmp -> next;
            i++;
        }
        printf("\n");
    }
}