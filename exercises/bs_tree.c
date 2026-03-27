#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* create_tree(Node *);
Node* insert_element(Node *,int);
Node* insert_element_recursive(Node *,int);
void preorder_traversal(Node *);
void inorder_traversal(Node *);
void postorder_traversal(Node *);
Node* find_smallest(Node *);
Node* find_largest(Node *);
Node* delete_element(Node *,int val);
Node* delete_element_recursive(Node *,int);
int binary_search(Node *,int val);
Node* mirror_image(Node *);
int total_nodes(Node *);
int total_external_nodes(Node *);
int total_internal_nodes(Node *);
int height(Node *);
Node* delete_tree(Node *);

int main()
{
    int choice, val;
    Node *tree,*ptr;
    tree=create_tree(tree);
    do
    {
        printf("\n\n******* BINARY SEARCH TREE OPERATIONS *******\n");
        printf("1. Insert Element\n");
        printf("2. Insert Element (Recursive)\n");
        printf("3. Delete Element\n");
        printf("4. Delete Element (Recursive)\n"); 
        printf("5. Search Element\n");
        printf("6. Inorder Traversal\n");
        printf("7. Preorder Traversal\n");
        printf("8. Postorder Traversal\n");
        printf("9. Find Smallest Element\n");
        printf("10. Find Largest Element\n");
        printf("11. Count Total Nodes\n");
        printf("12. Count External Nodes (Leafs)\n");
        printf("13. Count Internal Nodes\n");
        printf("14. Calculate Height\n");
        printf("15. Mirror Image of Tree\n");
        printf("16. Delete Entire Tree\n");
        printf("17. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                tree = insert_element(tree, val);
                break;
            
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                tree = insert_element_recursive(tree, val);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                tree = delete_element(tree, val);
                break;

            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                tree = delete_element_recursive(tree, val);
                break;

            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                if(binary_search(tree, val))
                    printf("Element %d found in the tree.\n", val);
                else
                    printf("Element %d NOT found in the tree.\n", val);
                break;

            case 6:
                printf("Inorder Traversal: ");
                inorder_traversal(tree);
                printf("\n");
                break;

            case 7:
                printf("Preorder Traversal: ");
                preorder_traversal(tree);
                printf("\n");
                break;

            case 8:
                printf("Postorder Traversal: ");
                postorder_traversal(tree);
                printf("\n");
                break;

            case 9:
                ptr = find_smallest(tree);
                if(ptr != NULL)
                    printf("Smallest Element is: %d\n", ptr->data);
                else
                    printf("Tree is empty.\n");
                break;

            case 10:
                ptr = find_largest(tree);
                if(ptr != NULL)
                    printf("Largest Element is: %d\n", ptr->data);
                else
                    printf("Tree is empty.\n");
                break;

            case 11:
                printf("Total Nodes: %d\n", total_nodes(tree)); 
                break;

            case 12:
                printf("Total External Nodes: %d\n", total_external_nodes(tree));
                break;

            case 13:
                printf("Total Internal Nodes: %d\n", total_internal_nodes(tree));
                break;

            case 14:
                printf("Height of the Tree: %d\n", height(tree));
                break;

            case 15:
                printf("Mirroring the tree...\n");
                mirror_image(tree);
                printf("Tree mirrored. Run a traversal to see changes.\n");
                break;

            case 16:
                printf("Deleting the entire tree...\n");
                delete_tree(tree);
                tree = NULL; // Ağacı sildikten sonra pointer'ı NULL yapmalıyız
                printf("Tree deleted.\n");
                break;

            case 17:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 17);
    return 0;
}

Node* create_tree(Node *tree)
{
    tree=NULL;
    return tree;
}

Node* insert_element(Node *tree,int val)
{
    Node *ptr,*node_ptr,*parent_ptr;
    node_ptr=(Node *)malloc(sizeof(Node));
    node_ptr->data=val;
    node_ptr->left=NULL;
    node_ptr->right=NULL;
    if (tree==NULL)
    {
        tree=node_ptr;
        return tree;
    }
    else 
    {
        parent_ptr=NULL;
        ptr=tree;
        while (ptr!=NULL)
        {
            parent_ptr=ptr;
            if (val<ptr->data) ptr=ptr->left;
            else ptr=ptr->right;
        }
        if (val<parent_ptr->data)parent_ptr->left=node_ptr;
        else parent_ptr->right=node_ptr;
    }
    return tree;
}

Node* insert_element_recursive(Node *tree,int val)
{
    if (tree==NULL)
    {
        Node *new_node;
        new_node=(Node *)malloc(sizeof(Node));
        new_node->data=val;
        new_node->left=NULL;
        new_node->right=NULL;
        return new_node;
    }
    if (val<tree->data)tree->left=insert_element_recursive(tree->left,val);
    else tree->right=insert_element_recursive(tree->right,val);
    return tree;
}

int binary_search(Node *tree,int val)
{
    if (tree==NULL) return 0;
    else if (tree->data==val) return 1;
    else if (val<tree->data) return binary_search(tree->left,val);
    else return binary_search(tree->right,val);
}

void preorder_traversal(Node *tree)
{
    if (tree!=NULL)
    {
        printf("%d ",tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

void inorder_traversal(Node *tree)
{
    if (tree!=NULL)
    {
        inorder_traversal(tree->left);
        printf("%d ",tree->data);
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(Node *tree)
{
    if (tree!=NULL)
    {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d ",tree->data);
    }
}

Node* find_smallest(Node *tree)
{
    if (tree==NULL || tree->left==NULL) return tree;
    else return find_smallest(tree->left);
}

Node* find_largest(Node *tree)
{
    if (tree==NULL || tree->right==NULL) return tree;
    else return find_largest(tree->right);
}

Node *delete_element(Node *tree,int val)
{
    Node *cur,*parent,*suc,*psuc,*ptr;
    if (tree==NULL)
    {
        printf("The tree is empty.\n");
        return tree;
    }
    parent=NULL;
    cur=tree;
    while (cur!=NULL && val!=cur->data)
    {
        parent=cur;
        if (val<cur->data) cur=cur->left;
        else cur=cur->right;
    }
    if (cur==NULL)
    {
        printf("The value is not found in the tree.\n");
        return tree;
    }
    if (cur->left==NULL) ptr=cur->right;
    else if (cur->right==NULL) ptr=cur->left;
    else 
    {
        psuc=cur;
        suc=cur->right;
        while (suc->left!=NULL)
        {
            psuc=suc;
            suc=suc->left;
        }
        if (cur==psuc)
        {
            suc->left=cur->left;
        }
        else 
        {
            suc->left=cur->left;
            psuc->left=suc->right;
            suc->right=cur->right;
        }
        ptr=suc;
    }
    if (parent == NULL) tree = ptr;
    else if (parent->left==cur) parent->left=ptr;
    else parent->right=ptr;
    free(cur);
    return tree;
}

Node* delete_element_recursive(Node *tree,int val)
{
    if (tree==NULL)return tree;
    if (val<tree->data) tree->left=delete_element_recursive(tree->left,val);
    else if (val>tree->data) tree->right=delete_element_recursive(tree->right,val);
    else 
    {
        if (tree->left==NULL)
        {
            Node *temp=tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right==NULL)
        {
            Node *temp=tree->left;
            free(tree);
            return temp;
        }
        else
        {
            Node *suc;
            suc=tree->right;
            while (suc->left!=NULL)
            {
                suc=suc->left;
            }
            tree->data=suc->data;
            tree->right=delete_element_recursive(tree->right,suc->data);
        }
    }
    return tree;
}

int height(struct node *tree)
{
    int leftheight, rightheight;
    if(tree==NULL)
        return 0;
    else
    {
        leftheight = height(tree->left);
        rightheight = height(tree->right);  
        if(leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}

int total_nodes(struct node *tree)
{
if(tree==NULL)
return 0;
else
return(total_nodes(tree->left) + total_nodes(tree->right) + 1);
}

int total_external_nodes(struct node *tree)
{
    if(tree==NULL)
        return 0;
    else if((tree->left==NULL) && (tree->right==NULL))
        return 1;
    else
        return (total_external_nodes(tree->left) +
    total_external_nodes(tree->right));
}

int total_internal_nodes(struct node *tree)
{
    if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
        return 0;
    else
        return (total_internal_nodes(tree->left)+ total_internal_nodes(tree->right) + 1);
}

struct node *mirror_image(struct node *tree)
{
    struct node *ptr;
    if(tree!=NULL)
    {
        mirror_image(tree->left);
        mirror_image(tree->right);
        ptr=tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}

struct node *delete_tree(struct node *tree)
{
if(tree!=NULL)
{
    delete_tree(tree->left);
    delete_tree(tree->right);
    free(tree);
}
}