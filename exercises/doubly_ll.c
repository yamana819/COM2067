#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* create_dll(struct node *start);
struct node* delete_after(struct node *start);
struct node* delete_beg(struct node *start);
struct node* display(struct node *start);
struct node* insert_end(struct node *start);
struct node* insert_before(struct node *start);
struct node* delete_end(struct node *start);

int main()
{
    int choice;
    struct node *start=NULL;
    puts("1: Display the list");
    puts("2: Add a new node before a given node");
    puts("3: Add a new node at the end");
    puts("4: Delete a node from the end");
    puts("5: Delete a node after a given node");
    puts("6: Delete a node from the beginning");
    puts("7: Create the doubly linked list");
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
            start=insert_before(start);
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
            start=delete_beg(start);
            break;
            case 7:
            start=create_dll(start);
            break;
        }
    }
    while (choice!=8);

}

struct node* create_dll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter -1 to end.\n");
    printf("Enter the data:");
    scanf("%d",&num);
    while (num!=-1)
    {
        if (start==NULL)
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->prev=NULL;
            new_node->data=num;
            new_node->next=NULL;
            start=new_node;
        }
        else 
        {
            ptr=start;
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            while (ptr->next!=NULL) ptr=ptr->next;
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
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
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    puts("");
    return start;
}

struct node* insert_end(struct node *start)
{
    struct node *ptr,*new_node;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while (ptr->next!=NULL) ptr=ptr->next;
    ptr->next=new_node;
    new_node->prev=ptr;
    new_node->next=NULL;
    return start;
}

struct node* insert_before(struct node *start)
{
    struct node *new_node,*ptr;
    int num,val;
    printf("Enter the data:");
    scanf("%d",&num);
    printf("Enter the value before which the node has to be inserted:");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while (ptr->data!=val) ptr=ptr->next;
    new_node->next=ptr;
    new_node->prev=ptr->prev;
    ptr->prev->next=new_node;
    ptr->prev=new_node;
    return start;
}

struct node* delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}

struct node* delete_end(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while (ptr->next!=NULL) ptr=ptr->next;
    ptr->prev->next=NULL;
    free(ptr);
    return start;
}

struct node* delete_after(struct node *start)
{
    struct node *ptr,*temp;
    int val;
    printf("Enter the value after which the node has to be deleted:");
    scanf("%d",&val);
    ptr=start;
    while (ptr->data!=val) ptr=ptr->next;
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    return start;
}