#include <stdio.h>
int main()
{
	float id,unit,amount,surcharge,total;
    char name[50];
	
	printf("enter ID :");
	scanf("%f",&id);
	printf("enter Name :");
	scanf("%s",name);
	printf("enter Units Consumed :");
	scanf("%f",&unit);

	
	if (unit <= 199.0){
		amount = 16.20*unit;
		printf(" your amount charge at @16.20 per unit is : %f",amount);
		
	}
	else if (unit >= 200.0 && unit < 300.0){
		amount = 20.10*unit;
		printf(" your amount charge at @20.50 per unit is: %f",amount);
	}
        else if (unit >= 300.0 && unit < 500.0){
    	        amount = 27.10*unit;
		printf(" your amount charge at @27.10 per unit is: %f",amount);
	}
	else if (unit >=500.0 ){
		amount = 35.90*unit;
		printf(" your amount charge at @35.90 per unit is: %f",amount);
	}
	else {printf("wrong unit entered\n");}
        
   
        if ( amount > 18000.0) {
           surcharge = 0.15*amount;
}

        printf(" \nCustomer ID : %.0f\n",id);
        printf(" Customer Name : %s\n",name);
        printf(" Units Consumed : %.0f\n",unit);
        printf(" Surcharge amount : %f\n",surcharge);
        printf(" Net amount paid by customer : %f\n",surcharge+amount);
	return 0;
}