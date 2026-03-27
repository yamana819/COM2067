#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node* display(struct node *start);
struct node* insert_beg(struct node *start);
struct node* insert_end(struct node *start);
struct node* delete_end(struct node *start);
struct node* delete_after(struct node *start);
struct node* delete_list(struct node *start);
struct node* create_cll(struct node *start);

int main()
{
    int choice;
    struct node *start=NULL;
    puts("1: Display the list");
    puts("2: Add a new node at the begining");
    puts("3: Add a new node at the end");
    puts("4: Delete a node from the end");
    puts("5: Delete a node after a given node");
    puts("6: Delete the list");
    puts("7: Create the circular linked list");
    puts("8: EXIT");
    do 
    {
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            start=display(start);
            break;
            case 2:
            start=insert_beg(start);
            break;
            case 3: 
            start=insert_end(start);
            break;
            case 4:
            start=delete_end(start);
            break;
            case 5:
            start=delete_after(start);
            break;
            case 6:
            start=delete_list(start);
            break;
            case 7:
            start=create_cll(start);
            break;
        }
    }
    while (choice!=8);
}

struct node* display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while (ptr->next!=start)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    return start;
}

struct node* insert_beg(struct node *start)
{
    struct node *new_ptr,*ptr;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    new_ptr=(struct node*)malloc(sizeof(struct node));
    new_ptr->data=num;
    ptr=start;
    while (ptr->next!=start) ptr=ptr->next;
    ptr->next=new_ptr;
    new_ptr->next=start;
    start=new_ptr;
    return start;
}

struct node* insert_end(struct node *start)
{
    struct node *new_ptr,*ptr;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    new_ptr=(struct node*)malloc(sizeof(struct node));
    new_ptr->data=num;
    ptr=start;
    while (ptr->next!=start) ptr=ptr->next;
    ptr->next=new_ptr;
    new_ptr->next=start;
    return start;
}

struct node* delete_end(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while (ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("Enter the value after which the node has to be deleted:");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while (preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

struct node* delete_list(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while (ptr->next!=start) start=delete_end(start);
    free(start);
    start=NULL;
    return start;
}

struct node* create_cll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    puts("Enter -1 to end:");
    printf("Enter the data:");
    scanf("%d",&num);
    while (num!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if (start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }
        else 
        {
            ptr=start;
            while (ptr->next!=start) ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=start;
        }
        printf("Enter the data:");
        scanf("%d",&num);
    }
    return start;
}