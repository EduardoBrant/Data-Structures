#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

struct que
{
    int size, front, rear;
    unsigned actualSize;
    int* arr; 
};

struct que* createque(unsigned actualSize)
{
    struct que* que = (struct que*)malloc(sizeof(struct que));
    que -> actualSize = actualSize;
    que -> front = que -> size = 0;
    que -> rear = actualSize -1;
    que -> arr = (int*)malloc(que->actualSize * sizeof(int));
    return que;
}

int isFull(struct que *que)
{
    return (que->size == que->actualSize);
}

void enqueue(struct que *que, int item)
{
    if(isFull(que)){
        return;
    }

    que->rear = (que->rear+1)%que->actualSize;
    que->arr[que->rear] = item;
    que->size = que->size+1;
    printf("\n%d enqueued to que\n",item);
}

int isEmpty(struct que *que)
{
    return (que->size == 0);
}

int dequeue(struct que *que)
{
    if(isEmpty(que)){
        return INT_MIN;
    }

    int item = que->arr[que->front];
    que->front = (que->front+1)%que->actualSize;
    que->size = que->size-1;
    return item; 
}

int front(struct que *que)
{
    if(isEmpty(que)){
        return INT_MIN;
    }
    return que->arr[que->front];
}

int rear(struct que *que)
{
    if(isEmpty(que)){
        return INT_MIN;
    }
    return que->arr[que->rear];
}

int main()
{
    int n, val;
    struct que *que = createque(100);

    do
    {
        printf("\n*******************************************************");
        printf("\n                          MENU                         ");
        printf("\n*******************************************************");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Is empty");
        printf("\n4.Is full");
        printf("\n5.First element");
        printf("\n6.Last element");
        printf("\n7.Exit");
        printf("\n\nEnter ur choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d",&val);
                enqueue(que,val);
                break;
            case 2:
                dequeue(que);
                break;
            case 3:
                printf((isEmpty(que)? "\nYes\n" : "\nNot\n"));
                break;
            case 4:
                printf((isFull(que)? "\nYes\n" : "\nNot\n"));
                break;
            case 5:
                printf("\nFront element : %d\n",front(que));
                break;
            case 6:
                printf("\nLast element : %d\n",rear(que));
                break;
            case 7: 
                exit(0);
                break;
            default:
                printf("\nWrong choice !! \n");
                break;
        }
    } while (1);
}