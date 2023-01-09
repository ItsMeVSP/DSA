#include<stdio.h>
#include<stdlib.h>
#define size 10
int hashfunc(int k)
{
    return k%11;
}
int dblhash(int k,int i)
{
    int h1,h2,fh;
    h1=k%11;
    h2=k%5;
    fh=(h1+(i*h2))%10;
    return fh;
}
void main()
{
    int i;
    int arr1[size];
    int key,hf,dh;
    printf("HASHING FUNCTION\n");
    for (i=0;i<size;i++)
    {
        arr1[i]=-1;
    }
    while(1)
    {
        printf("Enter the element:\n");
        scanf("%d",&key);
        hf=hashfunc(key);
        if(arr1[hf]==-1)
        {
            arr1[hf]=key;
            printf("The elements are:\n");
            for (i=0;i<size;i++)
            {
                printf("%d\t",arr1[i]);
            }
            printf("\n");
            continue;
        }
        printf("Collision occurs @ %d\n",i);
        for (i=0;i<size;i++)
        {
            dh=dblhash(key,i);
            if (arr1[dh]==-1)
            {
                arr1[dh]=key;
                printf("The elements are:\n");
                for (i=0;i<size;i++)
                {
                    printf("%d\t",arr1[i]);
                }
                printf("\n");
                break;
            }
            printf("Collision occurs @ %d\n",i);
        }
    }
}