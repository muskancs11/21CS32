#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front=0, rear=-1, count=0, q[MAX], item;

void insert()
{
    if (count == MAX)
        printf("Circular Queue Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);
        rear++;
        q[rear%MAX] = item;
        count = count+1;
    }
}

void del()
{
    if (count == 0)
        printf("Circular Queue Underflow\n");
    else
    {
        item = q[front];
        front = (front+1)%MAX;
        count = count -1;
        printf("Deleted element = %d\n", item);
    }
}

void display()
{
    int i, j=front;
    if (count == 0)
        printf("Circular Queue Underflow\n");
    else
    {
        printf("\n\t front = %d\t rear = %d\t Count = %d\n", front%MAX, rear%MAX, count);
        printf("Queue elements are: ");
        for(i=1;i<=count;i++)
        {
            printf("\t%d", q[j]);
            j = (j+1)%MAX;
        }
    }
}

int main()
{
    int ch;
    do{
        printf("\n\n\t Circular Queue Using Arrays\n");
        printf("\n\t <1> Insert");
        printf("\n\t <2> Delete");
        printf("\n\t <3> Display");
        printf("\n\t <4> Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
                display();
                break;
            case 2:
                del();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input");
                break;
        }
    }while(ch!=4);
    return 0;
}
