#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data; 
    struct stack *next;
};

struct stack* push(struct stack *top,int data);
struct stack* display(struct stack *top);
struct stack* pop(struct stack *top);
int peek(struct stack *top);

int main()
{
    int val,choice;
    puts("1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit");
    struct stack *top = NULL;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to be pushed: ");
                scanf("%d",&val);
                top = push(top,val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if (val != -1) printf("Top element is: %d\n",val);
                break;
            case 4:
                top = display(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

struct stack* push(struct stack *top,int data)
{
    struct stack *ptr;
    ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->data=data;
    if (top==NULL) 
    {
        ptr->next=NULL;
        top=ptr;
    }
    else 
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
}

struct stack* display(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if (top==NULL) puts("Stack is empty.");
    else 
    {
        while (ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
    return top;
}

struct stack* pop(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if (top==NULL) printf("Stack underflow.");
    else 
    {
        top=top->next;
        printf("The value being deleted is %d\n",ptr->data);
        free(ptr);
    }
    return top;
}

int peek(struct stack *top)
{
    if (top==NULL) return -1;
    else return top->data;
}