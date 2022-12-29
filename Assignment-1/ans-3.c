//Explain the implementation of multiple stacks, with relevant functions in C.

#include <stdio.h>
#include <malloc.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushA()
{
    int val;
    if(topA == topB-1)
        printf("\n\tMultiple Stack A Overflow");
    else
    {
        printf("\n\tEnter the value to push on stack A :");
        scanf("%d",&val);
        stack[++topA] = val;
    }
}

void popA()
{
    int val;
    if(topA == -1)
        printf("\n\tMultiple Stack A Overflow");
    else
    {
        val = stack[topA--];
        printf("\n\tThe value popped from Stack A = %d", val);

    }
}

void display_stackA()
{
    int i;
    if(topA == -1)
        printf("\n\tMultiple Stack A Underflow");
    else
    {
        for(i=topA;i>=0;i--)
            printf("\t %d",stack[i]);
    }
}

void pushB()
{
    int val;
    if(topB-1 == topA)
        printf("\n\tMultiple Stack B Overflow");
    else
    {
        printf("\n\tEnter the value to push on stack B :");
        scanf("%d",&val);
        stack[--topB] = val;
    }
}

void popB()
{
    int val;
    if(topB == MAX)
        printf("\n\tMultiple Stack B Underflow");
    else
    {
        val = stack[topB++];
        printf("\n\tThe value popped from Stack A = %d", val);

    }
}

void display_stackB()
{
    int i;
    if(topB == MAX)
        printf("\n\tMultiple Stack Underflow");
    else
    {
        for(i=topB;i<MAX;i++)
            printf("\t %d",stack[i]);
    }
}

int main()
{
    int option, val;
    do{
        printf("\n\n\tMultiple Stack\n");
        printf("\n\t<1> Push an element into Stack A");
        printf("\n\t<2> Push an element into Stack B");
        printf("\n\t<3> Pop an element from Stack A");
        printf("\n\t<4> Pop an element from Stack B");
        printf("\n\t<5> Display the elements of Stack A");
        printf("\n\t<6> Display the elements of Stack B");
        printf("\n\t<7> Exit");
        printf("\n\n\tEnter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            pushA();
            break;

        case 2:
            pushB();
            break;

        case 3:
            popA();
            break;

        case 4:
            popB();
            break;

        case 5:
            display_stackA();
            break;

        case 6:
            display_stackB();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid Input");
            break;
        }
    }while(option!=7);
    return 0;
}
