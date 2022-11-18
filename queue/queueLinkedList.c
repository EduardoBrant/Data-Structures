#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    unsigned data;
}*p, *tmp, *tmp1;

void insert_end(int);
void delete_beg();
void display();
void isEmpty();

int main()
{
    int n, val;
    p = NULL;

    do
    {
        printf("\n*******************************************************");
        printf("\n                          MENU                         ");
        printf("\n*******************************************************");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Is empty");
        printf("\n4.Display ");
        printf("\n5.Exit");
        printf("\n\nEnter ur choice : ");
        scanf("%d",&n);

        switch (n)
        {
        case 1:
            printf("\nEnter the value: ");
            scanf("%d", &val);
            insert_end(val);
            break;
        case 2:
            delete_beg();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            display();
            break;
        case 5: 
            exit(0);
            break;
        default:
            printf("\nWrong choice !!\n");
            break;
        }
    } while (1);
}

void insert_end(int val)
{
    tmp = p;
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1->data = val;
    tmp1->next = NULL;
    
    if(p == NULL){
        p = tmp1;
    }else{
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next= tmp1;
    }
}

void isEmpty(){
    if(p == NULL){
        printf("\nIs empty\n");
    }else{
        printf("\nIs not empty\n");
    }
}

void delete_beg()
{
    tmp = p;
    if(p == NULL){
        printf("\nNo element to be deleted !!\n");
    }else{
        printf("\nelement deleted : %d\n", p->data);
        p = p->next;
    }
}

void display()
{
    tmp = p;
    while (tmp != NULL)
    {
        printf("\n%d", tmp -> data);
        tmp = tmp->next;
    }
}
