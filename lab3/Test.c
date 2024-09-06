#include <stdio.h>

int main() 
{
    float principle,irate,tperiod,sint;
    
printf("Enter principle between the amount of  Rs.100 to Rs.1,000,000 : ");
scanf("%f",&principle);

if (principle < 100 || principle > 1000000) 
  {
printf("not in range");
  return 0;
}
  
printf("Enter Interest Rate Between 5 to 10 :");
scanf("%f",&irate);

if (irate < 5 || irate > 10)
{
printf("not in range");
  return 0;
}
  
printf("Enter Time Period Between 1 to 10 Years:");
scanf("%f",&tperiod);

if (tperiod < 1 || tperiod > 10)
{
printf("not in range");
  return 0;
}
  
  sint  = (principle*irate*tperiod)/100;
  printf("The Simple Interest is %f",sint);
  
}