#include <stdio.h>
int main() 
{ int ffuel,bfuel,fcost,favg,fconsume,dist;
dist = 1207;
ffuel = 118;
bfuel = 123;
printf("enter car fuel average : ");
scanf("%d",&favg);
if ( favg >0) 
{
fcost = (dist/favg)*ffuel + (dist/favg)*bfuel;
fconsume = (dist*2)/favg;
printf("\nfuel cost is : %d",fcost);
printf("\nfuel consumed is : %d",fconsume); 
} 
else printf("negative number try again");
return 0;
}


