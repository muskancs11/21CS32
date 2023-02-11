#include <stdio.h>
#include <stdlib.h>

struct qlist
{
    int usn;
    char name[20];
    char branch[20];
    struct qlist *next;
};
struct qlist *front=NULL, *rear=NULL;

void create()
{
    int i,n;
    printf("\n\t Creation of Queue using SLL");
    printf("\n\t Enter no. of elements to create: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        insert();
}

void insert()
{
    struct qlist *newnode;
    newnode = (struct qlist*)malloc(sizeof(struct qlist));
    printf("\n\t Enter USN: ");
    scanf("%d", &newnode->usn);
    printf("\t Enter Name: ");
    scanf("%s", &newnode->name);
    printf("\t Enter Branch: ");
    scanf("%s", &newnode->branch);
    newnode->next=NULL;
    if(front==NULL || rear==NULL)
    {
        front=rear = newnode;
    }
    else
    {
        rear->next=newnode;
        rear = newnode;
    }
}

void del()
{
    struct qlist *temp;
    if (front == NULL)
    {
        printf("\n\n\t Queue Underflow");
        return;
    }
    temp = front;
    front = front->next;
    printf("\n\t Deleted Student: USN=%d Name=%s Branch=%s\n", temp->usn, temp->name, temp->branch);
    free(temp);
}

void display()
{
    struct qlist *temp;
    if (front == NULL)
    {
        printf("\n\n\t Queue Underflow");
        return;
    }
    temp = front;
    printf("\n\n\t Queue Elements are: ");
    printf("\n\n\t USN \t Name \t \t Branch\n\n");
    while(temp!=NULL)
    {
        printf("\n\n\t %d \t %s \t %s\n", temp->usn, temp->name, temp->branch);
        temp = temp->next;
    }
}

struct qlist *concatenate (struct qlist *list1, struct qlist *list2, struct qlist *list3)
{
    struct qlist *temp = list1;
    if (list1==NULL)
        list3=list2;
    else if (list2==NULL)
        list3=list1;
    else
    {
        list3=list1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = list2;
    }
    return list3;
}

int main()
{
    int ch;
    int i,n,m;
    do{
        printf("\n\n\t Queue Using SLL\n");
        printf("\n\t\t <1> Creation");
        printf("\n\t\t <2> Insertion");
        printf("\n\t\t <3> Deletion");
        printf("\n\t\t <4> Concatenation of two SLL");
        printf("\n\t\t <5> Display");
        printf("\n\t\t <6> Exit");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                create();
                display();
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
                printf("\n\n\t Concatenation of two SLL");
                printf("\n\t Enter no. of elements in list 1 : ");
                scanf("%d", &n);
                for(i=0;i<n;i++)
                    insert();
                struct qlist *list1=front, *front=NULL;
                printf("\n\t Enter no. of elements in list 2 : ");
                scanf("%d", &m);
                for(i=0;i<m;i++)
                    insert();
                struct qlist *list2=front, *list3;
                concatenate(list1, list2, list3);
                front = list3;
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice");
                break;
        }
    }while(ch!=6);
    return 0;
}
