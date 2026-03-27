#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 25

int stack[MAX],top=-1;
int pop();
void push(int val);
int evaluatePrefix(char prefix[],int length);
int getType(char);

int main()
{
    char prefix[MAX];
    int val,len;
    printf("Enter any prefix expression:");
    fgets(prefix,MAX,stdin);
    prefix[strcspn(prefix,"\n")]='\0';
    len=strlen(prefix);
    val=evaluatePrefix(prefix,len);
    printf("The result is:%d",val);
}

int pop()
{
    int result=0;
    if (top==-1) 
    {
        puts("Stack underflow.");
        exit(1);
    }
    else result=stack[top--];
    return result;
}

void push(int val)
{
    if (top==MAX-1) 
    {
        puts("Stack overflow");
        exit(1);
    }
    else stack[++top]=val;
}

int getType(char c)
{
    if (c=='-'||c=='+'||c=='*'||c=='/'||c=='%') return 1;
    else if (isdigit(c)) return 0;
    else exit(1);
}

int evaluatePrefix(char prefix[],int length)
{
    int op1,op2,i,result,val;
    for (i=length-1;i>=0;i--)
    {
        switch (getType(prefix[i]))
        {
            case 0:
                val=prefix[i]-'0';
                push(val);
                break;
            case 1:
                op1=pop();
                op2=pop();
                switch (prefix[i])
                {
                    case '+':
                        result=op1+op2;
                        break;
                    case '-':
                        result=op1-op2;
                        break;
                    case '*':
                        result=op1*op2;
                        break;
                    case '/':
                        result=op1/op2;
                        break;
                    case '%':
                        result=op1%op2;
                        break;
                }
                push(result);
                break;
        }
    }
    return stack[0];
}
