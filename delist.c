#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head;
void insfront()
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
void insrear()
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
void insmiddle()
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
void delfront()
{
    int item;
    struct node *ptr;
    if (head==NULL)
    {
        printf("List is underflow\n");
    }
    else
    {
        item=head->val;
        ptr=head;
        head=head->next;
        printf("The value going to be deleted is %d",ptr->val);
        free(ptr);
    }
}
void delrear()
{
    struct node *prev;
    struct node *temp;
    if (head==NULL)
    {
        printf("List is underflow\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("The value going to be deleted is %d",temp->val);
        free(temp);
    }
}
void delmiddle()
{
    int i,n;
    struct node *prev;
    struct node *temp;
    printf("Enter the position:\n");
    scanf("%d",&n);
    if (head==NULL)
    {
        printf("List is underflow\n");
    }
    else
    {
        temp=head;
        for(i=0;i<n;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        printf("The value going to be deleted is %d",temp->val);
        free(temp);
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
        printf("1.Insert at Beginning\n2.Insert at middle\n3.Insert at end\n4.Delete at Beginning\n5.Delete at Middle\n6.Delete at End\n7.Display\nPress 0 for Exit\nChoose any one option");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("INSERTION AT BEGINNING\n");
            insfront();
            break;
        case 2:
            printf("INSERTION AT MIDDLE\n");
            insmiddle();
            break;
        case 3:
            printf("INSERTION AT END\n");
            insrear();
            break;
        case 4:
            printf("DELETION AT BEGINNING\n");
            delfront();
            break;
        case 5:
            printf("DELETION AT MIDDLE\n");
            delmiddle();
            break;
        case 6:
            printf("DELETION AT END\n");
            delrear();
            break;
        case 7:
            display();
            break;        
        default:
            printf("Wrong Option...Try Again\n");
            break;
        }    
    }   
}