#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[100];
    int  isbn;
    char author[100];
    struct Node *next;
} Node;

Node* addend(Node *head,Node *new)
{
    Node *ptr=head;
    while (ptr->next!=NULL)
    {   
        ptr=ptr->next;
    }
    ptr->next=new;
    return head;
}

Node* move_end(Node* head,char arr[])
{
    if (head==NULL)
    {
        return NULL;
    }
    else if (strcmp(head->title,arr)==0 && head->next==NULL)
    {
        return head;
    }
    else if (strcmp(head->title,arr)==0 && head->next!=NULL)
    {
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        addend(head,temp);
        return head;
    }
    else 
    {
        Node *ptr=head;
        while (ptr->next!=NULL && strcmp(ptr->next->title,arr)!=0)
        {
            ptr=ptr->next;
        }
        if (ptr->next==NULL)
        {
            printf("This title is not found in the list.\n");
        }
        else 
        {
            Node* hold=ptr->next;
            ptr->next=ptr->next->next;
            hold->next=NULL;
            addend(head,hold);
            return head;
        }
    }
}

Node* isbndell(int search,Node *head)
{
    if (head==NULL)
    {
        printf("The list is already empty.\n");
        return NULL;
    }
    else if (head->isbn==search)
    {
        Node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node *ptr=head;
    while (ptr->next!=NULL && ptr->next->isbn!=search)
    {
        ptr=ptr->next;
    }
    if (ptr->next==NULL)
    {
        printf("This isbn is not found in the list.\n");
    }
    else 
    {
        Node *temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
        return head;
    }
}

Node* create_node(char *title, int isbn, char *author) {
    Node *n = (Node*)malloc(sizeof(Node));
    strcpy(n->title,  title);
    strcpy(n->author, author);
    n->isbn = isbn;
    n->next = NULL;
    return n;
}


Node* add_beg(Node *head, char *title, int isbn, char *author) {
    Node *n = create_node(title, isbn, author);
    n->next = head;
    return n;
}


Node* add_end(Node *head, char *title, int isbn, char *author) {
    Node *n = create_node(title, isbn, author);
    if (head == NULL) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}


Node* del_beg(Node *head) {
    if (head == NULL) return NULL;
    Node *old = head;
    head = old->next;
    free(old);
    return head;
}


void print_list(Node *head) {
    if (head == NULL) { puts("(empty)"); return; }
    int i = 1;
    while (head) {
        printf("%d) %s | %s | %d\n", i, head->title, head->author, head->isbn);
        head = head->next; i++;
    }
}


int main(void) {
    Node *head = NULL;
    char cmd[32];

    while (scanf("%31s", cmd) == 1) {
        if (strcmp(cmd, "QUIT") == 0) break;

        if (strcmp(cmd, "ADD_BEG") == 0) {
            char title[100], author[100]; int isbn;
            scanf("%99s %d %99s", title, &isbn, author);
            head = add_beg(head, title, isbn, author);

        } else if (strcmp(cmd, "ADD_END") == 0) {
            char title[100], author[100]; int isbn;
            scanf("%99s %d %99s", title, &isbn, author);
            head = add_end(head, title, isbn, author);

        } else if (strcmp(cmd, "DEL_BEG") == 0) {
            head = del_beg(head);

        } else if (strcmp(cmd, "PRINT") == 0) {
            print_list(head);
        }
        else if (strcmp(cmd,"MOVE_END")==0)
        {
            char arr[100];
            scanf("%99s",arr);
            head=move_end(head,arr);
        }
        else if (strcmp(cmd,"DEL_ISBN")==0)
        {
            int search;
            scanf("%d",&search);
            head=isbndell(search,head);
        }
    }

    return 0;
}