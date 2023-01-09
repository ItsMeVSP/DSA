#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head;
void enq()
{
    int value;
    struct node *temp;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Not able to push\n");
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
        printf("Element Inserted\n");        
    }
}
void deq()
{
    int item;
    struct node *ptr;
    if(head==NULL)
    {
        printf("List is Underflow\n");
    }
    else
    {
        item=head->val;
        ptr=head;
        head=head->next;
        printf("The value is going to be deleted is %d\n",ptr->val);
        free(ptr);
    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if (ptr==NULL)
    {
        printf("The list is empty\n");
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
void search()
{
    int i=1,item;
    struct node *ptr;
    ptr=head;
    if (ptr==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Enter the element to search:\n");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(item==ptr->val)
            {
                printf("The element is stored in location %d\n",i);
                break;
            }
            ptr=ptr->next;
            i++;
        }
        if(ptr==NULL)
        {
            printf("The element is not found\n");    
        }
    }
}
void check()
{
    struct node *ptr;
    if (head==NULL)
    {
        printf("List is empty\n");
    }
    else if (ptr==NULL)
    {
        printf("List is full\n");
    }
    else
    {
        printf("List is inconsistent\n");
    }
}
void main()
{
    int choice;
    printf("IMPLEMENTATION OF QUEUE USING LINKED LIST\n");
    while (choice!=0)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Check\n5.Search\nPress 0 for Exit\nPlease enter an option:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("ENQUEUE\n");
            enq();
            break;
        case 2:
            printf("DEQUEUE\n");
            deq();
            break;
        case 3:
            printf("DISPLAY\n");
            display();
            break;
        case 4:
            printf("CHECKING FUNCTION\n");
            check();
            break;
        case 5:
            printf("SEARCH AND FIND\n");
            search();
            break;
        default:
            printf("Try Again...\n");
            break;
        }
    }
}