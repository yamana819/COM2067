#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    int coeff;
    struct node *next;
};

struct node* create_poly(struct node *start);
void display_poly(struct node *start);
struct node* add_poly(struct node *start1,struct node *start2,struct node *start3);
struct node* sub_poly(struct node *start1,struct node *start2, struct node *start3);
struct node* add_node(struct node *start,int num,int coeff);



int main()
{
    struct node *p1=NULL, *p2=NULL, *sum=NULL, *diff=NULL;
    int choice;
    do {
        printf("1: Create poly1\n2: Create poly2\n3: Display poly1\n4: Display poly2\n5: Add\n6: Subtract\n7: Display sum\n8: Display diff\n9: Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: p1 = create_poly(p1); break;
            case 2: p2 = create_poly(p2); break;
            case 3: display_poly(p1); break;
            case 4: display_poly(p2); break;
            case 5: sum = add_poly(p1,p2,sum); break;
            case 6: diff = sub_poly(p1,p2,diff); break;
            case 7: display_poly(sum); break;
            case 8: display_poly(diff); break;
        }
    } while(choice != 9);
}


struct node* create_poly(struct node *start)
{
    struct node *new_node,*ptr;
    int n,c;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Enter its coefficient:");
    scanf("%d",&c);
    while (n!=-1)
    {
        if (start==NULL)
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->coeff=c;
            new_node->num=n;
            new_node->next=NULL;
            start=new_node;
        }
        else 
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->coeff=c;
            new_node->num=n;
            ptr=start;
            while (ptr->next!=NULL) ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("Enter the number:");
        scanf("%d",&n);
        printf("Enter its coefficient:");
        scanf("%d",&c);
    }
    return start;
}

void display_poly(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while (ptr!=NULL) 
    {
        printf("%dx%d ",ptr->num,ptr->coeff);
        ptr=ptr->next;
    }
    puts("");
}

struct node* add_node(struct node *start,int num,int coeff)
{
    struct node *ptr,*new_node;
    if (start==NULL)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->num=num;
        new_node->coeff=coeff;
        new_node->next=NULL;
        start=new_node;
    }
    else 
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->num=num;
        new_node->coeff=coeff;
        ptr=start;
        while (ptr->next!=NULL) ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=NULL;
    }
    return start;
}

struct node* add_poly(struct node *start1,struct node *start2,struct node *start3)
{
    struct node *ptr1,*ptr2;
    int sum_num,c;
    ptr1=start1;
    ptr2=start2;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1->coeff==ptr2->coeff)
        {
            sum_num=ptr1->num+ptr2->num;
            start3=add_node(start3,sum_num,ptr1->coeff);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if (ptr1->coeff > ptr2->coeff)
        {
            start3=add_node(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            start3=add_node(start3,ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
    }
    if (ptr1==NULL)
    {
        while (ptr2!=NULL)
        {
            start3=add_node(start3,ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
    }
    if (ptr2==NULL)
    {
        while (ptr1!=NULL)
        {
            start3=add_node(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }
    }
    return start3;
}

struct node* sub_poly(struct node *start1,struct node *start2, struct node *start3)
{
    struct node *ptr1,*ptr2;
    int sub_num,c;
    ptr1=start1 , ptr2=start2;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1->coeff==ptr2->coeff)
        {
            sub_num=ptr1->num-ptr2->num;
            start3=add_node(start3,sub_num,ptr1->coeff);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if (ptr1->coeff > ptr2->coeff)
        {
            start3=add_node(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            start3=add_node(start3,-ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
    }
    if (ptr1==NULL)
    {
        while (ptr2!=NULL)
        {
            start3=add_node(start3,-ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
    }
    if (ptr2==NULL)
    {
        while (ptr1!=NULL)
        {
            start3=add_node(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }
    }
    return start3;
}