#include <stdio.h>
#include <stdlib.h>

int stack[10],top=-1;
int pop(int stack[]);
void push(int stack[],int val);

int main()
{
    int val,n,i;
    int arr[10];
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    if (0<n && n<=10)
    {
        printf("Enter the elements in the array:\n");
        for (i=0;i<n;i++) scanf("%d",&arr[i]);
        for (i=0;i<n;i++) push(stack,arr[i]);
        for (i=0;i<n;i++)
        {
            val=pop(stack);
            arr[i]=val;
        }
        printf("The reversed array is:");
        for (i=0;i<n;i++) printf("%d ",arr[i]);
    }
    else 
    {
        puts("Invalid size.");
    }
}

void push(int stack[],int val)
{
    stack[++top]=val;
}

int pop(int stack[])
{
    return stack[top--];
}