#include<stdio.h>
#include<string.h>
void main()
{
    int lines=0;
    printf("Enter line for upper diamond: ");
    scanf("%d",&lines);
    for (int i = 1; i <= lines; i++)
    {
        for (int j = i; j < lines; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= (2*i-1); j++)
        {
            printf("*");


        }
        printf("\n");

    
    }
       for (int i = lines-1; i >= 1; i--)
    {
        for (int j = lines; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= (2*i-1); j++)
        {
            printf("*");


        }
        printf("\n");

    
    }
}
