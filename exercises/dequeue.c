#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    int data;
    int priority;
    struct node *next;
};

struct node *insert(struct node *start);
struct node *delete(struct node *start);
void display(struct node *start);

int main()
{
    struct node *start=NULL;
    do 
    {
        int choice;
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                start=insert(start);
                break;
            case 2:
                start=delete(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                puts("Invalid choice.");
        }
    } while (1);
}

struct node *insert(struct node *start)
{
    int val,pri;
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value and it's priority:");
    scanf("%d %d",&val,&pri);
    ptr->data=val;
    ptr->priority=pri;
    if (start==NULL || pri<start->priority)
    {
        ptr->next=start;
        start=ptr;
    }
    else 
    {
        temp=start;
        while (temp->next!=NULL && temp->next->priority<=ptr->priority) temp=temp->next;
        ptr->next=temp->next;
        temp->next=ptr;
    }
    return start;
}

struct node* delete(struct node *start)
{
    struct node *temp;
    if (start==NULL)
    {
        puts("The dequeue is empty.");
    }
    else 
    {
        temp=start;
        start=start->next;
        printf("The deleted item is %d.",temp->data);
        free(temp);
    }
    return NULL;
}

void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if (start==NULL)puts("The dequeue is empty.");
    else 
    {
        while (ptr!=NULL)
        {
            printf("%d:%d ",ptr->priority,ptr->data);
            ptr=ptr->next;
        }
        puts("");
    }
}