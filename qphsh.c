#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls() (system("cls"))
#define pause() (system("pause"))

int main()
{
    const int size = 10;
    int table[10], key, value, c1 = 3, c2 = 5;
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }
    cls();
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
        printf("\nEnter value : ");
        scanf("%d", &value);
        for (int j = 0; j < size; j++)
        {
            key = (value + (j * c1) + (j * j * c2)) % 11;
            if (table[key] == -1)
            {
                table[key] = value;
                break;
            }
        }
        printf("\nTable\n");
        for (int j = 0; j < size; j++)
        {
            printf("%d ", table[j]);
        }
    }
    printf("\nTable is full.");
    return 0;
}
