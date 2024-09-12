#include <stdio.h>
int main()
{
	int num;
	printf("enter number : ");
	scanf("%d",&num);
	
	(num%2==0 && num%10==0 && num > 0)? printf("number is accepted"): printf("number is not accepted");
	
	return 0;
}
