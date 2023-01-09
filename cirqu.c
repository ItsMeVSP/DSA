#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *front;
struct node *rear;
void enq()
{
    printf("ENQUEUE\n");
    struct node *ptr;
    int item;
    printf("Enter item to insert:");
    scanf("%d",&item);
    if(front==NULL)
    {
       front=(struct node *)malloc(sizeof(struct node));
       front->val=item;
       front->next=NULL;
       rear=front;
    }
    else
    {
       ptr=(struct node *)malloc(sizeof(struct node));
       ptr->val=item;
       ptr->next=front;
       rear->next=ptr;
       rear=ptr;
    }
}
void deq()
{
    printf("DEQUEUE\n");
    struct node *ptr;
    if(front==NULL)
       printf("Queue is empty\n");
    else
    {
        ptr=front;
        front=front->next;
        rear->next=front;
        printf("Item deleted:%d\n",ptr->val);
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        ptr=front;
        printf("The elements are:\n");
        do
        {
            printf("Address:%p\nValue:%d\n",ptr->next,ptr->val);
            ptr=ptr->next;
        }while(ptr!=front);
    }
}
void search()
{
    int usr,i=1,flag=0;
    struct node *ptr;
    printf("SEARCH\n");
    printf("Enter the element to search:");
    scanf("%d",&usr);
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        ptr=front;
        do
        {
            if(ptr->val==usr)
            {
                printf("The element is stored in location %d\n",i);
                flag=1;
            }
            ptr=ptr->next;
            i++;
        }while(ptr!=front);
        if (flag==0)
        {
            printf("Element not found\n");
        }
    }
}
void main()
{
    int choice;
    printf("IMPLEMENTATION OF QUEUE IN CIRCULAR LINKED LIST\n");
    while(choice!=0)
    {
        printf("Operations:\n1.Insert\n2.Delete\n3.Display\n4.Search\nPress 0 for Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enq();break;
            case 2:deq();break;
            case 3:display();break;
            case 4:search();break;
            default:printf("Try Again...\n");break;
        }
    }
}
