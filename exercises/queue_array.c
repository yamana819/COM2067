#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert();
int delete_element();
int peek();
void display();

int main()
{
    do {
        int choice;
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                {
                    int deleted_value=delete_element();
                    if (deleted_value!=-1)
                    printf("Deleted value is %d\n",deleted_value);
                }
                break;
            case 3:
                {
                    int front_value=peek();
                    if (front_value!=-1)
                    printf("Front value is %d\n",front_value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                puts("Invalid choice.");
        }
    } while (1);
}

void insert()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if (rear==MAX-1)puts("Overflow.");
    else if (rear==-1 && front==-1)front=rear=0;
    else rear++;
    queue[rear]=num;
}

int delete_element()
{
    int val;
    if (front==-1 || front>rear)
    {
        puts("Underflow.");
        return -1;
    }
    else 
    {
        val=queue[front];
        front++;
        if (front>rear)
        front=rear=-1;
        return val;
    }
}

int peek()
{
    if (front==-1 || front>rear)
    {
        puts("Queue is empty.");
        return -1;
    }
    else 
    {
        return queue[front];
    }
}

void display()
{
    if (front==-1||front>rear)puts("Queue is empty.");
    else
    {
        for (int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}