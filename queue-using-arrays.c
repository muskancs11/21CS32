#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear = -1, front = 0, data, q[MAX];

void insert();
void del();
void display();

void main()
{
    int ch;
    do {
        printf("\n\n\tQueue Using Arrays\n");
        printf("\n\t <1> Insert");
        printf("\n\t <2> Delete");
        printf("\n\t <3> Display");
        printf("\n\t <4> Exit");
        printf("\n\n\t Enter your choice: ");
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
                printf("Invalid choice");
                break;

        }
    }while(ch!=4);
}

void insert()
{
    if (rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d", &data);
        rear++;
        q[rear] = data;
    }
}

void del()
{
    if (rear<front)
        printf("Queue Underflow\n");
    else
    {
        data = q[front];
        front++;
        printf("Deleted Element = %d", data);
    }
}

void display()
{
    int i;
    if (rear<front)
        printf("Queue Underflow\n");
    else
    {
        printf("Queue elements are: ");
        for(i=front; i<=rear; i++)
            printf("\t%d", q[i]);
    }
}
