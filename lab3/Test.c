#include <stdio.h>
int main() 
{ int taxrate,tax,salary;
printf("enter taxrate : ");
scanf("%d",&taxrate);
printf("\nenter salary : ");
scanf("%d",&salary);
tax = (taxrate/100.0)*salary;
salary = salary - tax;
printf("Your tax amount is %d and your remaining salary is %d",tax,salary);
return 0;
}



