#include <stdio.h>

void swapIntegers(int n1,int n2){
	int temp;
	
	printf("Before Swap\n");
	printf("Value at Number 1: %d\n",n1);
	printf("Value at Number 2: %d\n",n2);
	temp=n1;
	n1=n2;
	n2=temp;
	printf("After Swap\n");
	printf("Value at Number 1: %d\n",n1);
	printf("Value at Number 2: %d\n",n2);
	

}
int main() {
    int n1,n2;

    printf("enter value at for Number 1: ");
    scanf("%d",&n1);
    printf("enter value at for Number 2: ");
    scanf("%d",&n2);
    
   swapIntegers(n1,n2);

    return 0;
}
