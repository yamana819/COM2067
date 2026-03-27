#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void create_queue(struct queue *queue);
struct queue* insert(struct queue *queue,int val);
struct queue* delete_element(struct queue *queue);
struct queue* display(struct queue *queue);
int peek(struct queue *queue);


int main()
{
    struct queue *q;
    create_queue(q);
    do 
    {
        int choice, val;
        puts("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&val);
                q=insert(q,val);
                break;
            case 2:
                q=delete_element(q);
                break;
            case 3:
                q=display(q);
                break;
            case 4:
                val=peek(q);
                if (val==-1) printf("The queue is empty.\n");
                else printf("The front element is %d.\n",val);
                break;
            case 5:
                exit(0);
            default:
                puts("Invalid choice.");
        }
    } while (1);
}

void create_queue(struct queue *queue)
{
    queue->front=NULL;
    queue->rear=NULL;
}

struct queue* insert(struct queue *queue,int val)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    if (queue->front==NULL)
    {
        queue->front=ptr;
        queue->rear=ptr;
        queue->front->next=NULL;
    }
    else 
    {
        queue->rear->next=ptr;
        queue->rear=ptr;
        queue->rear->next=NULL;
    }
    return queue;
}

struct queue* display(struct queue *queue)
{
    struct node *ptr;
    ptr=queue->front;
    if (ptr==NULL)
    {
        puts("The queue is empty.");
        return NULL;
    }
    else 
    {
        while (ptr!=queue->rear)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }
    return queue;
}

struct queue* delete_element(struct queue *queue)
{
    struct node *ptr;
    ptr=queue->front;
    if (ptr==NULL)
    {
        printf("Underflow.");
        return NULL;
    }
    else 
    {
        queue->front=queue->front->next;
        printf("Deleted element is %d.",ptr->data);
        free(ptr);
        return queue;
    }
}

int peek(struct queue *queue)
{
    if (queue->front==NULL) return -1;
    else return queue->front->data;
}