#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void preorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ->", root->data);
        preorder(root->left);
        preorder(root->right);   
    }
}
void inorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ->", root->data);
        inorder(root->right);   
    }
}
void postorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ->", root->data);   
    }
}
struct node* createnode()
{
    
    int value;
    struct node *new=malloc(sizeof(struct node));
    printf("Enter the value:\n");
    scanf("%d",&value);
    if (value==-1)
    {
        return 0;
    }
    new->data=value;
    new->left=createnode();
    new->right=createnode();
    return new;
};
void insertleft()
{
    struct node* temp;
    int value,op1;
    printf("Enter value to insert:\n");
    scanf("%d",&value);
    if (root->left==NULL)
    {
        root->left=createnode(value);
    }
    else
    {
        temp=root;
        while (temp->left!=NULL)
        {
            temp=temp->left;
        }
        printf("Enter the position (Press 1 for Left and 2 for Right,No other options):\n");
        scanf("%d",&op1);
        if (op1==1)
        {
            temp->left=createnode(value);
            root=temp;
        }
        else if (op1==2)
        {
            temp->right=createnode(value);
            root=temp;
        }
        else
        {
            printf("Wrong Option...");
        }
    }
}
void insertright()
{
    struct node* temp;
    int value,op1;
    printf("Enter value to insert:\n");
    scanf("%d",&value);
    if (root->right==NULL)
    {
        root->right=createnode(value);
    }
    else
    {
        temp=root;
        while (temp->right!=NULL)
        {
            temp=temp->right;
        }
        printf("Enter the position (Press 1 for Left and 2 for Right,No other options):\n");
        scanf("%d",&op1);
        if (op1==1)
        {
            temp->left=createnode(value);
            root=temp;
        }
        else if (op1==2)
        {
            temp->right=createnode(value);
            root=temp;
        }
        else
        {
            printf("Wrong Option...");
        }
    }
}
void display()
{
    int choice1;
    printf("Please choose any one option:\n");
    printf("1.Pre-Order Traversal\n2.In-Order Traversal\n3.Post-Order Traversal\n");
    scanf("%d",&choice1);
    switch (choice1)
    {
    case 1:
        printf("PRE-ORDER TRAVERSAL\n");
        preorder(root);
        break;
    case 2:
        printf("IN-ORDER TRAVERSAL\n");
        inorder(root);
        break;
    case 3:
        printf("POST-ORDER TRAVERSAL\n");
        postorder(root);
        break;
    default:
        printf("Wrong Option\n");
        break;
    }
}
void search(struct node *root)
{
    int item,flag=0;
    printf("Enter the value to search:\n");
    scanf("%d",&item);
    if (root==NULL)
    {
        return;
    }
    else
    {
        if (root->data==item)
        {
            printf("Element is present\n");
            flag=1;
            return;
        }
        else
        {
            search(root->left);
            search(root->right);
        }
    }
    if(flag==0)
    {
        printf("Element is not present\n");
    }
}
void main()
{
    int choice,rootval;
    printf("BINARY TREE OPERATIONS\n");
    printf("Enter value for root node:\n");
    scanf("%d",&rootval);
    root=createnode(rootval);
    while (choice!=0)
    {
        printf("Please enter any one option:\n");
        printf("\n1.Insert to Left\n2.Insert to Right\n3.Traversal\n4.Search\nCaution:\nThis options is based on root node\nPress 0 for Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("INSERT LEFT\n");
            insertleft();
            break;
        case 2:
            printf("INSERT RIGHT\n");
            insertright();
            break;
        case 3:
            printf("TRAVERSAL\n");
            display();
            break;
        case 4:
            printf("SEARCH\n");
            search(root);
            break;
        default:
            printf("Wrong Option....");
            break;
        }
    }
}