#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int processID;
    int priority;
    int processTime;
    struct Node* prev;
    struct Node* next;
} Node;

Node* insertOrdered(Node *head,int processID,int priority,int processTime);
Node* deleteByPriority(Node *head);
Node* insertBefore(Node *head,int processID,int priority,int processTime,int search);
Node* createNode(int processID,int priority,int processTime);
Node* addBeg(Node* head, int processID,int priority,int processTime);
Node* addEnd(Node* head, int processID,int priority,int processTime);
Node* deleteBeg(Node* head);
Node* delEnd(Node* head);
void printList(Node* head);

int main() {
    Node* head = NULL;
    int num, prio, time;
    while (1)  
    { 
        scanf("%d", &num);
        if (num == -1)
            break;
        scanf("%d %d", &prio, &time);
        head = insertOrdered(head, num, prio, time);
    }
    printList(head);
    head = deleteByPriority(head);
    printList(head);
    return 0;
}

Node* deleteByPriority(Node *head)
{
    Node *temp=head;
    Node *ptr=head;
    int min=temp->processTime;
    while (ptr->next!=NULL && ptr->priority==ptr->next->priority)
    {
    ptr=ptr->next;
    if (ptr->processTime<min) min=ptr->processTime;
    }
    while (temp->processTime!=min) temp=temp->next;
    if (temp->prev==NULL)
    {
        head=deleteBeg(head);
        return head;    
    }
    else if (temp->next==NULL)
    {
        head=delEnd(head);
        return head;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    return head;
}

Node* insertOrdered(Node *head,int processID,int priority,int processTime)
{
    if (head==NULL)
    {
        head=addEnd(head,processID,priority,processTime);
        return head;
    }
    Node *ptr;
    int search;
    ptr=head;
    while (ptr->next!=NULL && ptr->priority<=priority) ptr=ptr->next;
    if (ptr->next==NULL && ptr->priority <= priority)
    {
        head=addEnd(head,processID,priority,processTime);
    }
    else if (ptr->prev==NULL && ptr->priority>priority)
    {
        head=addBeg(head,processID,priority,processTime);
        return head;
    }
    else
    {
        search=ptr->priority;
        head=insertBefore(head,processID,priority,processTime,search);
    }
    return head;
}

Node* insertBefore(Node *head,int processID,int priority,int processTime,int search)
{
    Node *n=createNode(processID,priority,processTime);
    Node* ptr;
    ptr=head;
    while (ptr->priority!=search) ptr=ptr->next;
    n->prev=ptr->prev;
    ptr->prev->next=n;
    n->next=ptr;
    ptr->prev=n;
    return head;
}

Node* createNode(int processID,int priority,int processTime) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->processID = processID;
    newNode->priority=priority;
    newNode->processTime=processTime;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* addBeg(Node* head, int processID,int priority,int processTime) {
    Node* n = createNode(processID,priority,processTime);
    if (head == NULL)
        return n;
    n->next = head;
    head->prev = n;
    head = n;
    return head; // yeni head
}

Node* addEnd(Node* head, int processID,int priority,int processTime) {
    Node* newNode = createNode(processID,priority,processTime);
    if (head == NULL) {
        return newNode; // Liste boşsa yeni düğüm head olur
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteBeg(Node* head) {
    if (head == NULL) {
        printf("Liste zaten bos.\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

Node* delEnd(Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d|%d ",temp->processID,temp->priority);
        temp = temp->next;
    }
    printf("\n");
}
