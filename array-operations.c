#include <stdio.h>
#include <stdlib.h>

int i,n,a[100], pos, val;
void create();
void display();
void insert();
void del();

int main()
{
    int choice;
    do{
        printf("\n\n\t Array Operations \n");
        printf("\n\t <1> Create");
        printf("\n\t <2> Display");
        printf("\n\t <3> Insert");
        printf("\n\t <4> Delete");
        printf("\n\t <5> Exit");
        printf("\n\t Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            insert();
            display();
            break;

        case 4:
            del();
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Input");
            break;
        }
    }while(choice!=5);
    return 0;
}

void create()
{
    printf("\n\t Enter the size of array: ");
    scanf("%d", &n);
    printf("\n\t Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void display()
{
    printf("\n\t The array elements are: \n");
    for(i=0;i<n;i++)
    {
        printf("\n\t\t a[%d]=%d", i,a[i]);
    }
}

void insert()
{
    printf("\n\t Enter the position:");
    scanf("%d", &pos);
    printf("\n\t Enter the value:");
    scanf("%d", &val);
    for(i=n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=val;
    n=n+1;
}

void del()
{
    printf("\n\t Enter the position:");
    scanf("%d", &pos);
    val = a[pos];
    for(i=pos;i<=n;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
}
