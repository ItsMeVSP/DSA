#include<stdio.h>
#include<stdlib.h>
char arr2[25];
int n,top=-1;
void insert()
{
    char item;
    int flag=0;
    printf("Enter the value:\n");
    scanf("%s",&item);
    if(top>=n-1)
    {
        printf("Stack is full\n");
    }
    else if(top==-1)
    {
        if(isalpha(item))
        {
            printf("Input is Character\n");
            flag=1;
            top++;
            arr2[top]=item;
            printf("Inserted Successfully\n");
        }
        else
        {
            printf("ERROR:Input is not Character\n");
            flag=0;
        }
    }
    else
    {
        if(isalpha(item))
        {
            printf("Input is Character\n");
            flag=1;
            if(arr2[top]==item)
            {
                printf("Not valid input\n");
                flag=0;
            }
            if(flag==1)
            {
                top++;
                arr2[top]=item;
                printf("Inserted Successfully\n");
            }
        }
        else
        {
            printf("ERROR:Input is not Character\n");
            flag=0;
        }
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements are:\n");
        for (i=top;i>=0;i++)
        {
            printf("%c\t",arr2[i]);
        }
        printf("\n");    
    }
}
void del()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Deleting Element %c\n",arr2[top]);
        top--;
    }
}
void oc()
{
    int i,j,count=0;
    for (i=0;i<=top;i++)
    {
        for (j=i+1;j<=top;j++)
        {
            if (arr2[i]==arr2[j])
            {
                count++;
            }  
        }
        printf("Count of %c is %d\n",arr2[i],count);
        count=0;
    }
}
void main()
{
    int i,choice;
    printf("CHAROPS USING STACK\n");
    printf("Enter the number of characters:\n");
    scanf("%d",&n);
    while(choice!=0)
    {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Occurrence Check\nPress 0 for Exit\nSelect any one option\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("INSERTION\n");
            insert();
            break;
        case 2:
            printf("DISPLAY\n");
            display();
            break;
        case 3:
            printf("DELETE\n");
            del();
            break;
        case 4:
            printf("OCCURENCE CHECKER\n");
            oc();
            break;
        default:
            printf("Wrong Option\n");
            break;
        }
    }
}