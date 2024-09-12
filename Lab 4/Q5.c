#include <stdio.h>
int main()
{
	float amount,newamount,discount;
	
	printf("enter total amount you spent :");
	scanf("%f",&amount);
	
	if (amount>= 500 && amount <= 2000){
		discount = amount*0.05;
		newamount = amount - discount;
		printf(" your amount before discount was %f",amount);
		printf(" \nyour discout amount is %f",discount);
		printf(" \nyour amount after discount was %f",newamount);
	}
	else if (amount >= 2000 && amount <=4000){
		discount = amount*0.1;
		newamount = amount - discount;
		printf(" your amount before discount was %f",amount);
		printf(" \nyour discout amount is %f",discount);
		printf(" \nyour amount after discount was %f",newamount);
	}
    else if (amount >= 4000 && amount <= 6000){
    	discount = amount*0.2;
    	newamount = amount - discount;
    	printf(" your amount before discount was %f",amount);
		printf(" \nyour discout amount is %f",discount);
		printf(" \nyour amount after discount was %f",newamount);
	}
	else if (amount >=6000 ){
		discount = amount*0.35;
		newamount = amount - discount;
		printf(" \nyour amount before discount was %f",amount);
		printf(" \nyour discout amount is %f",discount);
		printf(" \nyour amount after discount was %f",newamount);
	}
	else printf("no discount applied");
	return 0;
}
