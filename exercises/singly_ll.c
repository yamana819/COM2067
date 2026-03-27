#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create_ll(struct node *start);
struct node* display(struct node *start);
struct node* insert_beg(struct node *start); 
struct node* insert_end(struct node *start);
struct node* insert_before(struct node *start);
struct node* insert_after(struct node *start);
struct node* delete_beg(struct node *start);
struct node* delete_end(struct node *start);
struct node* delete_after(struct node *start);
struct node* delete_node(struct node *start);
struct node* delete_list(struct node *start);
struct node* sort_list(struct node *start);

int main()
{
    int choice;
    struct node *start=NULL;
    puts("1: Create a linked list");
    puts("2: Display the list");
    puts("3: Add a node at the begining");
    puts("4: Add a node at the and");
    puts("5: Add a node before a given node");
    puts("6: Add a node after a given node");
    puts("7: Delete a node from the begining");
    puts("8: Delete a node from the end");
    puts("9: Delete a given node");
    puts("10: Delete a node after a given node");
    puts("11: Delete the entire list");
    puts("12: Sort the list");
    puts("13: EXIT");
    do 
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
            start=create_ll(start);
            printf("The list is created.\n");
            break;
            case 2:
            start=display(start);
            break;
            case 3:
            start=insert_beg(start);
            break;
            case 4:
            start=insert_end(start);
            break;
            case 5:
            start=insert_before(start);
            break;
            case 6:
            start=insert_after(start);
            break;
            case 7:
            start=delete_beg(start);
            break;
            case 8:
            start=delete_end(start);
            break;
            case 9:
            start=delete_node(start);
            break;
            case 10:
            start=delete_after(start);
            break;
            case 11:
            start=delete_list(start);
            break;
            case 12:
            start=sort_list(start);
            break;
        }
    }
    while (choice!=13);
}

struct node* create_ll(struct node *start)
{
    struct node *newnode,*ptr;
    int num;
    printf("Enter -1 to terminate\n");
    printf("Enter the data:");
    scanf("%d",&num);
    while (num!=-1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if (start==NULL)
        {
            newnode->next=NULL;
            start=newnode;
        }
        else 
        {
            ptr=start;
            while (ptr->next!=NULL) ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("Enter the data:");
        scanf("%d",&num);
    }
    return start;
}

struct node* display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    puts("");
    return start;
}

struct node* insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}

struct node* insert_end(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    while (ptr->next!=NULL) ptr=ptr->next;
    ptr->next=new_node;
    return start;
}

struct node* insert_after(struct node *start)
{
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("Enter the data to be inserted:");
    scanf("%d",&num);
    printf("Enter the value after which the data has to be inserted:");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    preptr=ptr;
    while (preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;
}

struct node* delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}

struct node* delete_end(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while (ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}

struct node* delete_after(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("Enter the value after which the node has to be deleted:");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

struct node* insert_before(struct node *start)
{
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("Enter the data to be inserted:");
    scanf("%d",&num);
    printf("Enter the value before which the data has to be inserted:");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    preptr=ptr;
    while (ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;
}

struct node* delete_node(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("Enter the value of the node which has to be deleted:");
    scanf("%d",&val);
    ptr=start;
    if (ptr->data==val)
    {
        start=delete_beg(start);
        return start;
    }
    else 
    {
        while (ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}

struct node* delete_list(struct node *start)
{
    struct node *ptr;
    if (start!=NULL)
    {
        ptr=start;
        while (ptr!=NULL)
        {
            printf("%d is to be deleted next\n",ptr->data);
            start=delete_beg(ptr);
            ptr=start;
        }
    }
    return start;
}

struct node* sort_list(struct node *start)
{
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=start;
    while (ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while (ptr2!=NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;
}