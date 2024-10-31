#include <stdio.h>

int prime(int n){
	int div=0,i;

	for (i=2;i<n;i++){
		if (n%2==0){
			div++;
		}
	}
	if (div >0){
		return 1;
	}
	else { return 0;
	}
}

int main() {
    int n;

    printf("enter Number: ");
    scanf("%d",&n);
   
   int res=prime(n);
if (res){
	printf("Number is not prime");
}
else { printf("Number is  prime");
}
    return 0;
}
