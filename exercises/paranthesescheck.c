#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 25

int top=-1;
char stack[MAX];

void push(char);
char pop();

int main()
{
    char exp[MAX],temp;
    int i,flag=1;
    printf("Enter an expression:");
    fgets(exp,MAX,stdin);
    exp[strcspn(exp,"\n")]='\0';
    for (i=0;i<strlen(exp);i++)
    {
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{') push(exp[i]);
        if (exp[i]==')' || exp[i]==']' || exp[i]=='}') 
        {
            if (top==-1) flag=0;
            else 
            {
                temp=pop();
                if (exp[i]==')' && (temp=='[' || temp=='{')) flag=0;
                else if (exp[i]==']' && (temp=='(' || temp=='{')) flag=0;
                else if (exp[i]=='}' && (temp=='(' || temp=='[')) flag=0;
            }
        }
    }
    if (top>=0) flag=0;
    if (flag==1) puts("Valid expression.");
    else puts("Invalid expression.");
}

void push(char c)
{
    if (top==MAX-1) puts("Stack overflow.");
    else 
    {
        top++;
        stack[top]=c;
    }
}

char pop()
{
    if (top==-1) puts("Stack underflow.");
    else return stack[top--];
}
