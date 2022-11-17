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

    do
    {
        printf("\n*******************************************************");
        printf("\n                          MENU                         ");
        printf("\n*******************************************************");
	    printf("\n1. Insert element at top");
	    printf("\n2. Remove element from top");
	    printf("\n3. See top element");
	    printf("\n4. Is empty? ");
	    printf("\n5. Exit ");
	    printf("\n\nEnter ur choice : ");
        scanf("%d", &n);

        switch(n)
        {
            case 1 : 
                printf("\nenter the value: ");
                scanf("%d",&val);
                push(stack,val);
                break;
            case 2 : 
                if(stack -> top == -1){
                    printf("\nNo elements to be deleted\n");
                    break;
                }
                printf("\nelement removed : %d\n", pop(stack));
                break;
            case 3 :
                printf(isEmpty(stack) == 1 ? "\nNo element at top\n" : "\nTop number: %d\n", peek(stack));
                break;
            case 4 : 
                printf(isEmpty(stack) == 1 ? "\nYes\n" : "\nNot\n");
                break;
            case 5 : 
                exit(0);
                break;   
            default : 
                printf("\nWrong choice !!\n");
                break;
        }
    }while(1);
}