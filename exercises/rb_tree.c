#include <stdio.h>
#include <stdlib.h>

typedef enum {RED,BLACK}Color;

typedef struct node
{
    int data;
    Color color;
    struct node *left,*right,*parent;
}RBNode;


RBNode* insert(RBNode *tree,int data);
RBNode* case1(RBNode* tree,RBNode *new_node);
RBNode* case2(RBNode* tree,RBNode *new_node);
RBNode* case3(RBNode* tree,RBNode *new_node);
RBNode* case4(RBNode* tree,RBNode *new_node);
RBNode* case5(RBNode* tree,RBNode *new_node);
RBNode* grand_parent(RBNode *new_node);
RBNode* uncle(RBNode *new_node);
RBNode* rotate_left(RBNode *tree,RBNode *x);
RBNode* rotate_right(RBNode *tree,RBNode *y);
RBNode* inorder_traversal(RBNode *tree);

int main()
{
    RBNode* tree=NULL;
    do 
    {
        int data;
        printf("Enter data to be inserted (-1 to stop): ");
        scanf("%d",&data);
        if (data==-1)break;
        tree=insert(tree,data);
        printf("Inorder Traversal: ");
        inorder_traversal(tree);
        printf("\n");
    } while (1);
}

RBNode* insert(RBNode *tree,int data)
{
    RBNode *new_node,*parent,*ptr;
    new_node=(RBNode*)malloc(sizeof(RBNode));
    new_node->parent=new_node->right=new_node->left=NULL;
    new_node->color=RED;
    new_node->data=data;
    if (tree==NULL)
    {
        tree=new_node;
    }
    else 
    {
        parent=NULL;
        ptr=tree;
        while (ptr!=NULL)
        {
            parent=ptr;
            if (data<ptr->data)ptr=ptr->left;
            else ptr=ptr->right;
        }
        new_node->parent=parent;
        if (data<parent->data)parent->left=new_node;
        else parent->right=new_node;
    }
    return case1(tree,new_node);
}

RBNode* case1(RBNode *tree,RBNode *new_node)
{
    if (new_node->parent==NULL)
    {
        new_node->color=BLACK;
        return tree;
    }
    else return case2(tree,new_node);
}

RBNode* case2(RBNode* tree,RBNode *new_node)
{
    if (new_node->parent->color==BLACK)return tree;
    else return case3(tree,new_node);
}

RBNode* case3(RBNode* tree,RBNode *new_node)
{
    RBNode *unc,*gpr;
    unc=uncle(new_node);
    gpr=grand_parent(new_node);
    if ((unc!=NULL)&&(unc->color==RED))
    {
        new_node->parent->color=BLACK;
        unc->color=BLACK;
        gpr->color=RED;
        return case1(tree,gpr);
    }
    else return case4(tree,new_node);
}

RBNode* case4(RBNode *tree,RBNode *new_node)
{
    RBNode *gpr=grand_parent(new_node);
    if ((new_node==new_node->parent->right)&&(new_node->parent==gpr->left))
    {
        tree=rotate_left(tree,new_node->parent);
        new_node=new_node->left;
    }
    else if ((new_node==new_node->parent->left)&&(new_node->parent==gpr->right))
    {
        tree=rotate_right(tree,new_node->parent);
        new_node=new_node->right;
    }
    return case5(tree,new_node);
}

RBNode* case5(RBNode *tree,RBNode *new_node)
{
    RBNode *gpr;
    gpr=grand_parent(new_node);
    if ((new_node==new_node->parent->left) && (new_node->parent==gpr->left)) tree=rotate_right(tree,gpr);
    else if ((new_node==new_node->parent->right)&&(new_node->parent==gpr->right)) tree=rotate_left(tree,gpr);
    new_node->parent->color=BLACK;
    gpr->color=RED;
    return tree;
}

RBNode* grand_parent(RBNode *new_node)
{
    if ((new_node!=NULL)&&(new_node->parent!=NULL))return new_node->parent->parent;
    else return NULL;
}

RBNode* uncle(RBNode *new_node)
{
    RBNode *g_parent;
    g_parent=grand_parent(new_node);
    if (g_parent==NULL)return NULL;
    if (new_node->parent==g_parent->left)return g_parent->right;
    else return g_parent->left;
}

RBNode* rotate_left(RBNode *tree,RBNode *x)
{
    RBNode *y=x->right;
    x->right=y->left;
    if (y->left!=NULL)y->left->parent=x;
    y->parent=x->parent;
    if (x->parent==NULL)tree=y;
    else if (x==x->parent->left)x->parent->left=y;
    else x->parent->right=y;
    y->left=x;
    x->parent=y;
    return tree;
}

RBNode* rotate_right(RBNode *tree,RBNode *y)
{
    RBNode *x=y->left;
    y->left=x->right;
    if (x->right!=NULL)x->right->parent=y;
    x->parent=y->parent;
    if (y->parent==NULL)tree=x;
    else if (y==y->parent->left)y->parent->left=x;
    else y->parent->right=x;
    x->right=y;
    y->parent=x;
    return tree;
}

RBNode* inorder_traversal(RBNode *tree)
{
    if (tree==NULL)return tree;
    inorder_traversal(tree->left);
    printf("%d(%c) ", tree->data, (tree->color==RED ? 'R':'B'));
    inorder_traversal(tree->right);
    return tree;
}