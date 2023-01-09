#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *prev;
    struct node *next;
};
struct node *head;
struct node *last;
void enq()
{
    int item;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Enter the value:");
        scanf("%d",&item);
        if(head==NULL)
        {
            ptr->val=item;
            head=ptr;
            last=ptr;
        }
        else
        {
            ptr->val=item;
            ptr->prev=last;
            last->next=ptr;
            ptr->next=NULL;
            last=ptr;
        }
    }
}
void deq()
{
    struct node *ptr;
    if (head==NULL)
    {
        printf("Underflow\n");
    }
    else if (head->next==NULL)
    {
        head=NULL;
        printf("Node deleted-%d\n",head->val);
        free(head);
    }
    else
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        printf("Node deleted-%d\n",ptr->val);
        free(ptr);
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
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is inconsistent\n");
    }
}
void disfor()
{
   struct node *ptr = head;
   while(ptr!= NULL) 
   {        
      printf("%d\n",ptr->val);
      ptr = ptr->next;
   }
}
void disback()
{
   struct node *ptr=last;
   while(ptr!=head) 
   {        
      printf("%d\n",ptr->val);
      ptr = ptr->prev;
   }
   printf("%d\n",ptr->val);
}
void search()
{
   int usr,i=1,flag=0;
   printf("Enter the value to search:");
   scanf("%d",&usr);
   struct node *ptr = head;
   while(ptr != NULL) 
   {        
      if(ptr->val==usr)
      {
            printf("The item is stored in location %d\n",i);
            flag=1;
      }
      ptr = ptr->next;
      i++;
   }
   if (flag==0)
   {
        printf("Element not found\n");
   }  
}
void main()
{
    int choice;
    printf("IMPLEMENTATION OF QUEUE USING DOUBLY LINKED LIST\n");
    while (choice!=0)
    {
        printf("Select any one option:\n1.Enqueue\n2.Dequeue\n3.Display(Forward)\n4.Display(Backward)\n5.Search\n6.Check if empty or not\nPress 0 for Exit\n");
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
            printf("DISPLAY FORWARD\n");
            disfor();
            break;
        case 4:
            printf("DISPLAY BACKWARD\n");
            disback();
            break;
        case 5:
            printf("SEARCH\n");
            search();
            break;
        case 6:
            printf("CHECK\n");
            check();
            break;
        default:
            printf("Wrong Option...\n");
            break;
        }
    }
}