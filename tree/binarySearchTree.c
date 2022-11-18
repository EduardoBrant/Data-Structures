 #include <stdio.h>
 #include <stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};

struct bst* insert(struct bst *q, int val)
{
    struct bst *temp;
    if(q == NULL)
    {
        temp=(struct bst *)malloc(sizeof(struct bst));
        temp->data= val;
        temp->left= NULL;
        temp->right= NULL;
        q = temp;
    }else{
        if(val < (q->data))
        {
            q->left= insert(q->left,val);
        }else{
            q->right=insert(q->right,val);
        }
    }
    return q;
}

void display(struct bst *q)
{
    if(q == NULL){
        return;
    }

    display(q->left);
    printf(" %d ",q->data);
    display(q->right);
}

struct bst* search(struct bst *p, int key, struct bst **y)
{
    struct bst *temp;
    if(p == NULL)
    {
        return (NULL);
    }

    temp = p;
    *y = NULL;
    while (temp != NULL)
    {
        if(temp->data == key)
        {
            return (temp);
        }else{
            *y = temp;
            if(temp-> data > key)
            {
                temp = temp -> left;
            }else{
                temp = temp -> right;
            }
        }
    }
    return (NULL);   
}

struct bst* del(struct bst *p,int val)
{
    struct bst *x, *y, *temp;
    x = search(p,val,&y);

    if(x == NULL)
    {
        printf("\nThe nodes not exists !! \n\n");
        return (p);
    }else{
        if(x==p)
        {
            temp = x->left;
            y = x->right;
            p = temp;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = y;
            free(x);
            return (p);
        }

        if(x->left != NULL && x->right != NULL)
        {
            if(y->left == x)
            {
                temp = x->left;
                y->left= x->left;
                while (temp->right != NULL)
                {
                    temp= temp->right;
                }
                temp->right = x->right;
                x->left = NULL;
                x->right = NULL;
            }else{
                temp = x->right;
                y->right = x->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                temp->left = NULL;
                temp->right = NULL;
            }
            free(x);
            return (p);
        }

        if(x->left == NULL && x->right != NULL)
        {
            if(y->left == x)
            {
                y->left = x->right;
            }else{
                y->right = x->right;
                x->right = NULL;
            }
            free(x);
            return (p);
        }

        if (x->left != NULL && x->right == NULL)
        {
            if(y->left == x)
            {
                y->left = x->left;
            }else{
                y->right = x ->left;
                x->left = NULL;
            }
            free(x);
            return (p);
        }
        
        if(x->left == NULL && x->right ==NULL)
        {
            if(y-> left == x)
            {
                y->left = NULL;
            }else{
                y->right = NULL;
            }
            free(x);
            return (p);
        }
    }
}

int main()
{
    struct bst *root = NULL;
    int val,num,n;

    printf("\nEnter no. of term: ");
    scanf("%d",&n);

    printf("\n");
    do
    {
        printf("Enter element: ");
        scanf("%d",&val);
        root = insert(root,val);
    } while(--n != 0);

    printf("\n\nDisplay element: ");
    display(root);
    printf("\nEnter element to be deleted: ");
    scanf("%d", &num);
    del(root,num);
    printf("Display element after deleted: ");
    display(root);
    printf("\n\n");

    return 0;
}