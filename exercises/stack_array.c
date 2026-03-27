#include <stdio.h>
#include <stdlib.h>
#define MAX 7

void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);
int stack[MAX],top=-1;

int main()
{
    int choice,val;
    puts("1: PUSH");
    puts("2: POP");
    puts("3: PEEK");
    puts("4: DISPLAY");
    puts("5: EXIT");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d",&val);
                push(stack,val);
                break;
            case 2:
                val=pop(stack);
                if (val!=-1) printf("The popped value is %d\n",val);
                break;
            case 3:
                val=peek(stack);
                if (val!=-1) printf("The topmost value is %d\n",val);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                exit(0);
            default:
                puts("Invalid choice.");
                break;
        }
    }    
}

void push(int stack[],int val)
{
    if (top==MAX-1) puts("Stack overflow.");
    else 
    {
        top++;
        stack[top]=val;
    }
}

int pop(int stack[])
{
    int val;
    if (top==-1) 
    {
        puts("Stack underflow.");
        return -1;
    }
    else 
    {
        val=stack[top];
        top--;
        return val;
    }
}

int peek(int stack[])
{
    if (top==-1) 
    {
        puts("The stack is empty.");
        return -1;
    }
    else return stack[top];
}

void display(int stack[])
{
    int i;
    if (top==-1) puts("The stack is empty.");
    else 
    {
        for (i=top;i>=0;i--) printf("%d\n",stack[i]);
    }
}