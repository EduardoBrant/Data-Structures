#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};

struct bst* insert(struct bst *,int);
void inorder(struct bst *);
void preorder(struct bst *);
void postorder(struct bst *);

int main()
{
    struct bst *r = NULL;

    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        int n = 0;
        printf("Enter the value: ");
        scanf("%d", &n);
        r = insert(r,n);
    }
    
    printf("\nDisplay element in inoder: ");
    inorder(r);
    printf("\nDisplay element in preorder: ");
    preorder(r);
    printf("\nDisplay element in postorder: ");
    postorder(r);
    printf("\n\n");
    
    return 0;
}

struct bst* insert(struct bst *q, int val)
{
    struct bst *tmp;
    tmp = (struct bst *)malloc(sizeof(struct bst));

    if(q == NULL){
        tmp->data = val;
        tmp->left = tmp->right = NULL;
        return tmp;
    }else{
        if(val  < (tmp -> data))
        {
            q->left = insert(q->left,val);
        }else{
            q->right = insert(q->right,val);
        }
    }
    return q;
}

void inorder(struct bst *q)
{
    if(q == NULL){
        return;
    }

    inorder(q->right);
    printf(" %d ",q->data);
    inorder(q->left);
}

void preorder(struct bst *q)
{
    if(q != NULL)
    {
        printf(" %d ",q->data);
        preorder(q->left);
        preorder(q->right);
    }
}

void postorder(struct bst *q)
{
    if(q != NULL)
    {
        postorder(q->left);
        postorder(q->right);
        printf(" %d ",q->data);
    }
}
