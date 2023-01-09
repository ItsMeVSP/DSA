#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head;
void front()
{
    int value;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Not able to push the element\n");
    }
    else
    {
        printf("Enter the value:\n");
        scanf("%d",&value);
        if(head==NULL)
        {
            ptr->val=value;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->val=value;
            ptr->next=head;
            head=ptr;
        }
        printf("Element Inserted Successfully at the beginning\n");
    }
}
void rear()
{
    int value;
    struct node *temp;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Not able to push the element\n");
    }
    else
    {
        printf("Enter the value:\n");
        scanf("%d",&value);
        if(head==NULL)
        {
            ptr->val=value;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            ptr->val=value;
            ptr->next=NULL;
            temp->next=ptr;
        }
        printf("Element Inserted Successfully at the end\n");
    }
}
void middle()
{
    int n,value,i;
    struct node *temp;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Not able to push the element\n");
    }
    else
    {
        printf("Enter the element:\n");
        scanf("%d",&value);
        printf("Enter the position:\n");
        scanf("%d",&n);
        if (n-1==0)
        {
            ptr->val=value;
            ptr->next=head;
            head=ptr;
        }
        else
        {
            temp=head;
            for(i=0;i<n-1;i++)
            {
                temp=temp->next;
            }
            ptr->val=value;
            ptr->next=temp->next;
            temp->next=ptr;
        }
        printf("Element inserted successfully at middle\n");
    }      
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if (ptr==NULL)
    {
        printf("The list is empty");        
    }
    else
    {
        printf("The elements are:\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->val);
            ptr=ptr->next;
        }
    }
}
void main()
{
    int choice;
    printf("INSERTION OF LINKED LIST\n");
    printf("Enter any one option:\n");
    while(choice!=0)
    {
        printf("Enter any one option:\n");
        printf("1.Insert at Beginning\n2.Insert at middle\n3.Insert at end\n4.Display\nPress 0 for Exit\nChoose any one option");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("INSERTION AT BEGINNING\n");
            front();
            break;
        case 2:
            printf("INSERTION AT MIDDLE\n");
            middle();
            break;
        case 3:
            printf("INSERTION AT END\n");
            rear();
            break;
        case 4:
            display();
            break;        
        default:
            printf("Wrong Option...Try Again\n");
            break;
        }    
    }   
}