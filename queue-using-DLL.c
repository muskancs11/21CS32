#include <stdio.h>
#include <stdlib.h>

struct list
{
    struct list *prev;
    char id[20];
    char name[20];
    char branch[20];
    char area[20];
    struct list *next;
};
struct list *front=NULL, *rear=NULL;

struct list *getnode()
{
    struct list *newnode;
    newnode = (struct list*)malloc(sizeof(struct list));
    printf("\n\tEnter ID: ");
    scanf("%s", newnode->id);
    printf("\tEnter Name: ");
    scanf("%s", newnode->name);
    printf("\tEnter Branch: ");
    scanf("%s", newnode->branch);
    printf("\tEnter Area of Specialization: ");
    scanf("%s", newnode->area);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void create()
{
    int i,n;
    printf("\n\t Creation of queue using DLL");
    printf("\n\t Enter the no. of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        insert();
    }
}

void insert()
{
    struct list *newnode;
    newnode=getnode();
    if (front==NULL || rear==NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear = newnode;
    }
}

void del()
{
    struct list *temp = front;
    if (front == NULL)
    {
        printf("\n\t Doubly Linked list is empty");
        return;
    }
    if (front->next==NULL)
    {
        front = NULL;
        free(temp);
    }
    else
    {
        front=front->next;
        front->prev=NULL;
        printf("\n\t Deleted Professor Data: ID=%s Name=%s Branch=%s Area of specialization=%s", temp->id, temp->name, temp->branch, temp->area);
        free(temp);
    }
}

void display()
{
    struct list *temp=front;
    int count=0;
    if (front == NULL)
    {
        printf("\n\t Doubly Linked List is empty");
        return;
    }
    else
    {
        printf("\n\tProfessor's Data: \n");
        printf("\n\t ID \t NAME \t BRANCH \t AREA OF SPECIALIZATION\n");
        while(temp!=NULL)
        {
            printf("\n\t %s \t %s \t %s \t %s", temp->id, temp->name, temp->branch, temp->area);
            temp = temp->next;
            count++;
        }
        printf("\n\t Total no. of Nodes = %d", count);
    }
}

int main()
{
    int i, n, ch;
    do{
        printf("\n\n\t Queue using Doubly linked list (DLL)");
        printf("\n\t\t <1> Creation");
        printf("\n\t\t <2> Insertion");
        printf("\n\t\t <3> Deletion");
        printf("\n\t\t <4> Display");
        printf("\n\t\t <5> Exit");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                insert();
                display();
                break;
            case 3:
                del();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\n Invalid choice");
                break;

        }
    }while(ch!=5);
    return 0;
}
