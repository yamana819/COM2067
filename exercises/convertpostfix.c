#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;
void push(char st[],char);
char pop(char st[]);
void infixtoPostfix(char source[],char target[]);
int getPriority(char);

int main()
{
    char infix[MAX],postfix[MAX];
    printf("Enter any infix expression:");
    fgets(infix,MAX,stdin);
    infix[strcspn(infix, "\n")] = '\0';
    strcpy(postfix,"");
    infixtoPostfix(infix,postfix);
    printf("The corresponding postfix expression is %s",postfix);
}

void push(char st[],char c)
{
    if (top==MAX-1) puts("Stack overflow");
    else 
    {
        top++;
        st[top]=c;
    }
}

char pop(char stack[])
{
    char val=' ';
    if (top==-1) puts("Stack underflow");
    else 
    {
        val=stack[top];
        top--;
    }
    return val;
}

int getPriority(char op)
{
    if (op=='/' || op=='*' || op=='%') return 1;
    else if (op=='-' || op=='+') return 0;
}

void infixtoPostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while (source[i]!='\0')
    {
        if (source[i]=='(')
        {
            push(stack,source[i]);
            i++;
        }
        else if (source[i]==')')
        {
            while (top!=-1 && stack[top]!='(')
            {
                target[j]=pop(stack);
                j++;
            }
            if (top==-1)
            {
                puts("Incorrect expression.");
                exit(1);
            }
            temp=pop(stack);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if (source[i]=='+' || source[i]=='*' || source[i]=='-' || source[i]=='/' || source[i]=='%')
        {
            while (top!=-1 && stack[top]!='('  && getPriority(stack[top])>=getPriority(source[i]))
            {
                target[j]=pop(stack);
                j++;
            }
            push(stack,source[i]);
            i++;
        }
        else 
        {
            puts("Incorrect element in expression.");
            exit(1);
        }
    }
    while (top!=-1 && stack[top]!='(')
    {
        target[j]=pop(stack);
        j++;
    }
    target[j]='\0';
}