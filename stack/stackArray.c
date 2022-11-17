#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack{
    int top;
    unsigned size;
    int *array;
};

struct stack* create(unsigned size)
{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack -> size = size;
    stack -> top  = -1;
    stack -> array = (int*)malloc(stack -> size *sizeof(int));
    return stack;
};

int isFull(struct stack* stack){
    return stack -> top == stack -> size -1;
}

int isEmpty(struct stack* stack){
    return stack -> top == -1;
}

void push(struct stack* stack, int item){
    if(isFull(stack)){
        return;
    }

    stack->array[++stack->top] = item;
}

int pop(struct stack* stack){
    if(isEmpty(stack)){
        return -1;
    }
        
    return stack -> array[stack-> top--];    
}

int peek(struct stack* stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }
    return stack -> array[stack -> top];
}

int main(){
    int val, n;
    struct stack* stack = create(100);

    do{
        printf("\n*******************************************************");
        printf("\n                          MENU                         ");
        printf("\n*******************************************************");
	    printf("\n1. Inserir elemento no topo");
	    printf("\n2. Remover elemento do topo");
	    printf("\n3. Ver elemento do topo");
	    printf("\n4. Esta vazia? ");
	    printf("\n5. Sair ");
	    printf("\n\nescolha uma das opções acima : ");
        scanf("%d", &n);

        switch(n)
        {
            case 1 : 
                printf("\nDIgite um valor: ");
                scanf("%d",&val);
                push(stack,val);
                break;
            case 2 : 
                printf("\nnumero removido : %d\n", pop(stack));
                break;
            case 3 : 
                printf("\nnumero do topo : %d\n", peek(stack));
                break;
            case 4 : 
                printf(isEmpty(stack) == 1 ? "\nSim\n" : "\nNão\n");
                break;
            case 5 : 
                exit(0);
                break;   
            default : 
                printf("\nOpção Invalida!\n");
                break;
        }
    }while(1);
}