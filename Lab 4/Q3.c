#include <stdio.h>
int main()
{
	int num1,num2;
	char op;
	
	printf("enter operator : ");
	scanf("%c",&op);
	printf("enter number 1 : ");
	scanf("%d",&num1);
	printf("enter number 2 : ");
	scanf("%d",&num2);
	
	
	switch(op){
		case '+':
			printf("\nanswer is : %d",num1+num2);
			break;
		case '-':
			printf("\nanswer is : %d",num1-num2);
			break;
	    case '*':
			printf("\nanswer is : %d",num1*num2);
			break;
		case '/':
			printf("\nanswer is : %d",num1/num2);	
			break;
		default : printf("wrong operator");
			
			
	}
	return 0;
}
