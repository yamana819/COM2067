#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* create_cdll(struct node *start);
struct node* insert_beg(struct node *start);
struct node* delete_node(struct node *start);
struct node* delete_beg(struct node *start);
void display_ll(struct node *start);

int main()
{
    int choice;
    struct node *start=NULL;
    puts("1 :Create the circular doubly linked list.");
    puts("2 :Insert a new node at the begining of the list.");
    puts("3 :Delete the node which is given by user.");
    puts("4 :Delete a node from the begining of the list");
    puts("5 :Display the list.");
    puts("6 :Exit");
    do 
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                start=create_cdll(start);
                break;
            case 2:
                start=insert_beg(start);
                break;
            case 4:
                start=delete_beg(start);
                break;
            case 3:
                start=delete_node(start);
                break;
            case 5:
                display_ll(start);
                break;
        }
    }while (choice!=6);
}

void display_ll(struct node *start)
{
    struct node *ptr=start;
    while (ptr->next!=start) 
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
    puts("");
}


struct node* create_cdll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    puts("Enter -1 to end.");
    printf("Enter the data:");
    scanf("%d",&num);
    while (num!=-1)
    {
        if (start==NULL)
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->prev=new_node;
            new_node->data=num;
            new_node->next=new_node;
            start=new_node;
        }
        else 
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            ptr=start;
            while (ptr->next!=start) ptr=ptr->next;
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=start;
            start->prev=new_node;
        }
        printf("Enter the data:");
        scanf("%d",&num);
    }
    return start;
}

struct node* insert_beg(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while (ptr->next!=start) ptr=ptr->next;
    new_node->prev=ptr;
    ptr->next=new_node;
    new_node->next=start;
    start->prev=new_node;
    start=new_node;
    return start;
}

struct node* delete_beg(struct node *start)
{
    if (start->next==start)
    {
        free(start);
        return NULL;
    }
    struct node *ptr,*temp;
    ptr=start;
    while (ptr->next!=start) ptr=ptr->next;
    ptr->next=start->next;
    temp=start;
    start=start->next;
    start->prev=ptr;
    free(temp);
    return start;
}

struct node* delete_node(struct node *start)
{
    struct node *ptr;
    int num;
    printf("Enter the data to be deleted:");
    scanf("%d",&num);
    ptr=start;
    if (ptr->data==num)
    {
        start=delete_beg(start);
        return start;
    }
    else 
    {
        while (ptr->data!=num && ptr->next!=start) ptr=ptr->next;
        if (ptr->data!=num && ptr->next==start)
        {
            printf("The data is not found in the list.\n");
            return start;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
        return start;
    }
} 

