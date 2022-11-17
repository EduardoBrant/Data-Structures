#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *p, *tmp, *tmp1, *end;

void insert_end(int);
void display();
void delete_end();
void isEmpty();

int main(){
    int val,n;
    p = NULL;

    do
    {
        printf("\n*******************************************************");
        printf("\n                          MENU                         ");
        printf("\n*******************************************************");
        printf("\n1.Push");
	    printf("\n2.Pop");
	    printf("\n3.Is empty?");
	    printf("\n4.Display");
	    printf("\n5.Exit");
	    printf("\n\nEnter ur choice : ");
	    scanf("%d",&n);

        switch(n)
        {
            case 1:
                printf("\nenter the value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 2:
                delete_end();
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
    }while(1);
}

void insert_end(int ele){
    tmp = p;
    tmp1 = (struct node*)malloc(sizeof(struct node*));
    tmp1 -> data = ele;
    tmp1 -> next = NULL;

    if(p == NULL){
        p = tmp1;
    }else{
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = tmp1;
    }
    end = tmp1;
}

void delete_end(){
    tmp = p;
    struct node* pre;

    if (p == NULL){
        printf("\nno element to be deleted\n");
    }else if(p-> next == NULL){
        printf("\nelement deleted : %d\n", p -> data);
        p = NULL;
        end = NULL;
    }else{
        while(tmp -> next != NULL){
            pre = tmp;
            tmp = tmp -> next;
        }
        pre -> next = NULL;
        end = pre;
        printf("\nelement deleted : %d\n", tmp -> data);
    }
}

void isEmpty(){
    if(p == NULL){
        printf("\nStack is empty\n");
    }else{
        printf("\nStack no is empty\n");
    }
}

void display(){
    tmp = p;

    if(tmp == NULL){
        printf("\nno elements to display\n");
        return;
    }

    while(tmp != NULL){
        printf("\n%d", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}