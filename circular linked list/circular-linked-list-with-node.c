#include <stdio.h>
#include <stdlib.h>

//NODE STRUCTURE

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;

//NODE CREATION

struct node *getnode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n\t Enter the Element:");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    return newnode;
}

void insert_front()
{
    struct node *newnode, *temp=start;
    newnode = getnode();
    if (start==NULL)
    {
        newnode->next=newnode;
        start = newnode;
    }
    else
    {
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=start;
        start = newnode;
    }
}

void insert_end()
{
    struct node *newnode, *temp=start;
    newnode = getnode();
    if (start==NULL)
    {
        newnode->next=newnode;
        start = newnode;
    }
    else
    {
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=start;
    }
}

void insert_any_position()
{
    struct node *newnode, *temp=start, *prev=NULL;
    int pos, i, len;
    len=length();
    printf("\n\n\tEnter position for the new element: ");
    scanf("%d",&pos);
    newnode = getnode();
    if(pos==1)
    {
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=start;
        start = newnode;
    }
    else if(pos==len)
    {
        while(temp->next!=start)
        {
            prev = temp;
            temp=temp->next;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
    else if(pos>len)
    {
        printf("\n\n\t You have entered position out of range.");
    }
    else
    {
        for(i=2;i<=pos-1;i++)
        {
            temp = temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void insert_before_node()
{
    struct node *newnode, *cur=start, *prev=NULL;
    int val;
    printf("\n\n\tEnter node value before which you want to insert: ");
    scanf("%d",&val);
    newnode = getnode();
    if(cur->data==val)
    {
        while(cur->next!=start)
        {
            cur = cur->next;
        }
        cur->next=newnode;
        newnode->next=start;
    }
    else
    {
        while(cur->data!=val)
        {
            prev = cur;
            cur = cur->next;
            if(cur==start)
            {
                break;
            }
        }
        if(cur->data == val)
        {
            prev->next=newnode;
            newnode->next=cur;
        }
        else
        {
            printf("\n\n\t You entered a wrong node value.");
        }
    }
}

void insert_after_node()
{
    struct node *newnode, *cur=start, *nxt=NULL ;
    int val;
    printf("\n\n\tEnter node value after which you want to insert: ");
    scanf("%d",&val);
    newnode = getnode();
    if(cur->data==val)
    {
        newnode->next=cur->next;
        cur->next=newnode;
    }
    else
    {
        while(cur->data!=val)
        {
            cur=cur->next;
            nxt=cur->next;
            if(nxt==start)
            {
                break;
            }
        }
        if(cur->data==val)
        {
            cur->next=newnode;
            newnode->next=nxt;
            if(nxt==start)
            {
                start = newnode;
            }
        }
        else
        {
            printf("\n\n\t You entered a wrong node value.");
        }
    }
}

void delete_front()
{
    struct node *temp=start;
    if(start == NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
        return;
    }
    if (temp->next==start)
    {
        start = NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=start)
        {
            temp = temp->next;
        }
        temp->next=start->next;
        free(start);
        start = temp->next;
    }
}

void delete_end()
{
    struct node *temp=start, *prev=NULL;
    if(start == NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
        return;
    }
    if (temp->next==start)
    {
        start = NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=start)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}

void delete_any_position()
{
    struct node *newnode, *temp=start, *prev=NULL;
    int pos, i, len;
    len=length();
    printf("\n\n\tEnter position to delete element: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        delete_front();
    }
    else if(pos==len)
    {
        delete_end();
    }
    else if(pos>len)
    {
        printf("\n\n\t You have entered position out of range.");
    }
    else
    {
        for(i=2;i<=pos;i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}

void delete_before_node()
{
    struct node *newnode, *cur=NULL, *prev=NULL, *nxt=start;
    int val;
    printf("\n\n\tEnter node value before which you want to delete: ");
    scanf("%d",&val);
    if(nxt->data==val)
    {
        delete_end();
    }
    else
    {
        while(nxt->data!=val)
        {
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
            if(nxt->next==start)
            {
                break;
            }
        }
        if(nxt->data==val)
        {
            if(prev==NULL)
            {
                delete_front();
            }
            else
            {
                prev->next=nxt;
                free(cur);
            }
        }
        else
        {
            printf("\n\n\t You entered a wrong node value.");
        }
    }
}

void delete_after_node()
{
    struct node *newnode, *cur=NULL, *prev=start, *nxt=NULL;
    int val;
    printf("\n\n\tEnter node value after which you want to delete: ");
    scanf("%d",&val);
    if(prev->data==val)
    {
        cur = prev->next;
        nxt = cur->next;
        prev->next=nxt;
        free(cur);
    }
    else
    {
        while(prev->data!=val)
        {
            prev = prev->next;
            cur = prev->next;
            nxt = cur->next;
            if(prev->next==start)
            {
                break;
            }
        }
        if(prev->data==val)
        {
            prev->next=nxt;
            if(cur==start)
            {
                start = cur->next;
            }
            free(cur);
        }
        else
        {
            printf("\n\n\t You entered a wrong node value.");
        }
    }
}

void search_sorted()
{
    int count=1, val;
    struct node *temp=start;
    if (start == NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
        return;
    }
    else
    {
        printf("\n\n\t Enter element to search: ");
        scanf("%d", &val);
        if (temp->data==val)
        {
            printf("\n\n\tElement %d found at position %d", val, count);
        }
        temp = temp->next;
        count = count + 1;
        while (temp->data<=val && temp!=start)
        {
            if (temp->data==val)
            {
                printf("\n\n\tElement %d found at position %d", val, count);
                return;
            }
            else
            {
                temp = temp->next;
                count++;
            }
        }
        printf("\n\n\tElement %d not found", val);
    }
}

void search_not_sorted()
{
    int count=1, val;
    struct node *temp=start;
    if (start == NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
        return;
    }
    else
    {
        printf("\n\n\t Enter element to search: ");
        scanf("%d", &val);
        if (temp->data==val)
        {
            printf("\n\n\tElement %d found at position %d", val, count);
        }
        do
        {
            if (temp->data==val)
            {
                printf("\n\n\tElement %d found at position %d", val, count);
                return;
            }
            else
            {
                temp = temp->next;
                count++;
            }
        }while (temp!=start);
        printf("\n\n\tElement %d not found", val);
    }
}

void reverse()
{
    struct node *curnode=start, *prevnode=NULL, *nextnode=NULL;
    if(start == NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
    }
    else
    {
        nextnode=curnode->next;
        curnode->next=prevnode;
        prevnode=curnode;
        curnode=nextnode;
        while(curnode!=start)
        {
            nextnode=curnode->next;
            curnode->next=prevnode;
            prevnode=curnode;
            curnode=nextnode;
        }
        start = prevnode;
    }
}

void display()
{
    struct node *temp=start;
    if(start == NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
    }
    else
    {
        while(temp->next!=start)
        {
            if(temp->next!=start)
            {
                printf("\t %d", temp->data);
                temp = temp->next;
            }
        }
        printf("\t %d", temp->data);
    }
}

int length()
{
    struct node *temp=start;
    int count =0;
    if (start==NULL)
    {
        printf("\n\n\t Circular Linked List is Empty\n");
        return;
    }
    else
    {
        count = 1;
        temp=temp->next;
        while(temp!=start)
        {
            count = count + 1;
            temp = temp->next;
        }
        return count;
    }
}

int main()
{
    int ch, count;
    do{
    printf("\n\n\t\t Circular Linked List (CLL)\n");
    printf("\n\t\t <1>  Insert at Front");
    printf("\n\t\t <2>  Insert at End");
    printf("\n\t\t <3>  Insert at Any Position");
    printf("\n\t\t <4>  Insert Before Node");
    printf("\n\t\t <5>  Insert After Node");
    printf("\n\t\t <6>  Delete at Front");
    printf("\n\t\t <7>  Delete at End");
    printf("\n\t\t <8>  Delete at Any Position");
    printf("\n\t\t <9>  Delete Before Node");
    printf("\n\t\t <10> Delete After Node");
    printf("\n\t\t <11> Search (Sorted List)");
    printf("\n\t\t <12> Search (Not Sorted List)");
    printf("\n\t\t <13> Reverse");
    printf("\n\t\t <14> Display");
    printf("\n\t\t <15> Length");
    printf("\n\t\t <16> Exit\n");
    printf("\n\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            insert_front();
            display();
            break;

        case 2:
            insert_end();
            display();
            break;

        case 3:
            insert_any_position();
            display();
            break;

        case 4:
            insert_before_node();
            display();
            break;

        case 5:
            insert_after_node();
            display();
            break;

        case 6:
            delete_front();
            display();
            break;

        case 7:
            delete_end();
            display();
            break;

        case 8:
            delete_any_position();
            display();
            break;

        case 9:
            delete_before_node();
            display();
            break;

        case 10:
            delete_after_node();
            display();
            break;

        case 11:
            search_sorted();
            display();
            break;

        case 12:
            search_not_sorted();
            display();
            break;

        case 13:
            reverse();
            display();
            break;

        case 14:
            display();
            break;

        case 15:
            count = length();
            display();
            printf("\n\n\t Length of circular linked list is = %d", count);
            break;

        case 16:
            exit(0);
    }
    }while(ch!=16);
    return 0;
}
