#include <stdio.h>
int main()
{
	int num;
	printf("enter number : ");
	scanf("%d",&num);
	
	if (num%3==0){
		printf("\nthis number is a multiple of 3");
		
	}
    else {
	printf("\nthis number is not a multiple of 3");
	}
	return 0;
}
