#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct Stack 
{
    Node *top;
    int size;
}Stack;

void initialize(Stack *stack);
void push(Stack *stack,int value);
int pop(Stack *stack);
int peek(Stack *stack);
void printStack(Stack *stack);

int main()
{
    Stack s;
    char *tempstring;
    int value,choice=0;
    initialize(&s);
    do
    {
        puts("1: Push a new node to the stack.");
        puts("2: Pop a value from the stack.");
        puts("3: Display the top element.");
        puts("4: Display the stack.");
        puts("5: Exit");
        printf("Enter your choice:");
        if (scanf("%d",&choice)==0)fgets(tempstring,100,stdin);
        switch (choice)
        {
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                push(&s,value);
                break;
            case 2:
                printf("%d\n",pop(&s));
                break;
            case 3:
                printf(peek(&s)?"%d":"\n",peek(&s));
                break;
            case 4:
                printStack(&s);
                break;
            default:
                puts("Invalid input.");
                continue;
                break;
        }
    }while (choice!=5);
}

void printStack(Stack *stack)
{
    Node *current_node;
    current_node=stack->top;
    while (current_node!=NULL)
    {
        printf("%d\n",current_node->data);
        current_node=current_node->next;
    }
}

int peek(Stack *stack)
{
    if (stack->top!=NULL) return stack->top->data;
    else return 0;
}

int pop(Stack *stack)
{
    if (stack->top==NULL)
    {
        puts("Stack underflow.");
        return -1;
    }
    else 
    {
        Node *ptr;
        int temp;
        ptr=stack->top;
        temp=stack->top->data;
        stack->top=ptr->next;
        free(ptr);
        stack->size--;
        return temp;
    }
}

void push(Stack *stack,int value)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->next=stack->top;
    stack->top=new_node;
    stack->size++;
}

void initialize(Stack *stack)
{
    stack->top=NULL;
    stack->size=0;
}