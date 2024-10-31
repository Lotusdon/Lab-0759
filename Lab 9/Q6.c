#include <stdio.h>
#include <string.h>
int high(int a[]){
	int i,high=-9999;
	for ( i = 0;i<10;i++){
		if( a[i]>high){
			high = a[i];
		}
	}
	return high;
}

int low(int a[]){
	int i,low=9999;
	for ( i = 0;i<10;i++){
		if( a[i]<low){
			low = a[i];
		}
	}
	return low;
}

int main() {
    int i=0,c,res;
    
   int arr[10];
   
   for (int i=0 ;i<10;i++){
   	printf("Enter value at Element %d : ",i+1);
   	scanf("%d",&arr[i]);
   }
   
   printf("\n");
    printf("Enter 1 to Calculate Highest Number\n");
    printf("Enter 2 to Calculate Lowest Number\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    
    switch(c){
    	case 1: 
    	  res=high(arr);
    	  printf("Highest Number is : %d\n",res);
    	  break;
    	
    	case 2:
    	  res=low(arr);
    	  printf("Lowest Number is : %d\n",res);
    	  break;
    	
		
		  
		default: printf("Invalid Input\n") ;        
	}
   
}
