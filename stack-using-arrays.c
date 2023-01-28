#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int s[MAX], item, top =0;
void push();
void pop();
void display();
int isempty();
int isfull();

void main()
{
    int ch;
    do{
        printf("\n\n\t Stack Using Arrays\n");
        printf("\n\t <1> Push");
        printf("\n\t <2> Pop");
        printf("\n\t <3> Display");
        printf("\n\t <4> Exit");
        printf("\n\n\t Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                push();
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice");
                break;
        }
    }while(ch!=4);
}

int isempty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (top == MAX)
        return 1;
    else
        return 0;
}

void push()
{
    if (isfull())
        printf("\n\tStack Overflow\n");
    else
    {
        printf("\n\t Enter element to be inserted: ");
        scanf("%d", &item);
        top = top + 1;
        s[top] = item;
    }
}

void pop()
{
    if (isempty())
        printf("\n\tStack Underflow\n");
    else
    {
        item = s[top];
        top = top - 1;
        printf("Deleted item = %d", item);
    }
}

void display()
{
    int i;
    if (isempty())
        printf("\n\tStack Underflow\n");
    else
    {
        printf("Stack elements are: ");
        for (i=top ;i>0 ;i--)
        {
            printf("\t%d", s[i]);
        }
    }
}
