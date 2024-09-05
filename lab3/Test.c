#include <stdio.h>
int main() 
{ int x,y,z;
printf("enter number 1 : ");
scanf("%d",&x);
printf("\nenter number 2 : ");
scanf("%d",&y);
z = x;
x = y;
y = z;
printf("\nnumber 1 is %d ",x);
printf("\nnumber 2 is %d ",y);
return 0;
}



