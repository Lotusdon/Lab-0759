#include <stdio.h>

int add(int n1,int n2){
int sum = n1+n2;
return sum;
}

int minus(int n1,int n2){
int minus = n1-n2;
return minus;
}

int multiply(int n1,int n2){
int multi = n1*n2;
return multi;
}

int div(int n1,int n2){
int div = n1/n2;
return div;
}

int main() {
    int n1,n2,res,c;

    printf("enter Number 1: ");
    scanf("%d",&n1);
    printf("enter Number 2: ");
    scanf("%d",&n2);
    
    printf("\n");
    printf("Enter 1 to Calculate addition\n");
    printf("Enter 2 to Calculate substraction\n");
    printf("Enter 3 to Calculate multiplication\n");
    printf("Enter 4 to Calculate division\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    
    switch(c){
    	case 1: 
    	  res=add(n1,n2);
    	  printf("Addition result is : %d\n",res);
    	  break;
    	
    	case 2:
    	  res=minus(n1,n2);
    	  printf("Substraction result is : %d\n",res);
    	  break;
    	case 3:  
    	  res=multiply(n1,n2);
    	  printf("Multiplication result is : %d\n",res);
    	  break;
		case 4:
		  res=div(n1,n2);
    	  printf("Division result is : %d\n",res);
    	  break;
		
		  
		default: printf("Invalid Input\n") ;        
	}
    
   
   
}
