#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

float stack[MAX];
int top=-1;
void push(float stack[],float val);
float pop(float stack[]);
float evaluatePostfix(char exp[]);

int main()
{
    float val;
    char exp[MAX];
    printf("Enter any postfix expression:");
    fgets(exp,MAX,stdin);
    exp[strcspn(exp,"\n")]='\0';
    val=evaluatePostfix(exp);
    printf("Value of the postfix expression:%.2f",val);
}

void push(float stack[],float val)
{
    if (top==MAX-1) puts("Stack overflow.");
    else 
    {
        top++;
        stack[top]=val;
    }
}

float pop(float stack[])
{
    float val=-1;
    if (top==-1) puts("Stack underflow");
    else 
    {
        val=stack[top];
        top--;
    }
    return val;
}

float evaluatePostfix(char exp[])
{
    int i=0;
    float op1,op2,value;
    while (exp[i]!='\0')
    {
        if (isdigit(exp[i])) push(stack,(float)(exp[i]-'0'));
        else 
        {
            op2=pop(stack);
            op1=pop(stack);
            switch (exp[i])
            {
                case '+':
                    value=op1+op2;
                    break;
                case '-':
                    value=op1-op2;
                    break;
                case '*':
                    value=op1*op2;
                    break;
                case '/':
                    value=op1/op2;
                    break;
                case '%':
                    value=(int)op1%(int)op2;
                    break;
            }
            push(stack,value);
        }
        i++;
    }
    return pop(stack);
}