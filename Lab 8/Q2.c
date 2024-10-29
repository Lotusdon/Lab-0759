#include<stdio.h>
#include<string.h>
void main()
{
    int s=0, in=1, x=0;
    printf("enter the number: ");
    scanf("%d",&s);
    if (s%2==0)
    {
        s-=1;
    }
    x=s;
    for (int i = s; i >=in; i-=2)
    {
        for (int j = 1; j <= i; j++)
        {
            if(x>0)
            {
                printf("%d ",x);
                x-=2;
            }
        }
        printf("\n");
        in++;
    }
    
}
