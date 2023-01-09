#include<stdio.h>
#include<stdlib.h>
int queue[100];
int front=-1,rear=-1,n;
void enq()
{
    int value;
    printf("Enter element:");
    scanf("%d",&value);
    if(rear==n-1)
    {
        printf("Queue is full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=value;
        printf("Value Inserted\n");
    }
    else
    {
        rear++;
        queue[rear]=value;
        printf("Value Inserted\n");
    }
}
void deq()
{
    int item;
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
        printf("Deleted element is %d\nPosition:%d\n",item,front);
    }
}
void display()
{
    int i;
    if(rear==-1)
    {
        printf("The Queue is empty\n");
    }
    else
    {
        printf("The elements are...\n");
        for (i=front;i<=rear;i++)
        {
            printf("\n%d--%d\n",queue[i],i);
        }
    }
}
void search()
{
    int i,item,pos=1;
    if(rear==-1)
    {
        printf("The Queue is empty\n");
    }
    else
    {
        printf("Enter the element:\n");
        scanf("%d",&item);
        for(i=front;i<=rear;i++)
        {
            if(item==queue[i])
            {
                printf("The element %d is stored in the position %d\n",item,pos);
            }
            pos++;
        }
    }
}
void check()
{
    if(rear==n-1 && front==0)
    {
        printf("Queue is full\n");
    }
    else if(rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is inconsistent\n");
    }
}
void main()
{
    int choice;
    printf("Enter the no.of elements:");
    scanf("%d",&n);
    printf("IMPLEMENTATION OF QUEUE USING ARRAY\n");
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