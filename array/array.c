#include <stdio.h>
#include <stdbool.h>

void display(int array[])
{
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%i\n", array[i]);
    }
}

void insert(int array[])
{
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
        printf("enter the value : ");
        scanf("%d", &array[i]);
    }    
}

int main()
{
    int array[10], n;
    bool firstPlay = true;

    do
    {
        printf("\n*******************************************************");
        printf("\n                          MENU                         ");
        printf("\n*******************************************************");
        printf("\n1.Insert values");
        printf("\n2.Display");
        printf("\n3.Exit");
        printf("\n\nEnter ur choice: ");
        scanf("%d",&n);

        switch (n)
        {
        case 1:
            insert(array);
            break;
        case 2:
            if(firstPlay == false){
                display(array);
                break;
            }else{
                printf("\nNo elements in array\n");
                firstPlay = false;
                break;
            }
        case 3:
            exit(0);
            break;
        default:
            printf("\nWrong choice !!\n");
            break;
        }
    } while (1);
}


