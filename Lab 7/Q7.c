#include <stdio.h>

int main() {
    char str[100];
    int result = 0, num = 0;
    char operation='+' ;  

   
    printf("Enter an expression:\t");
    scanf("%s", str);
    
   
    for (int i = 0; str[i] != '\0'; i++) {
       
        if ((str[i] == '+' || str[i] == '-') && str[i+1] == '\0') {
            printf("Invalid expression: operator at the end.\n");
            return 0;
        }
        
        else if (str[i] >= '0' && str[i] <= '9') {
            num = (num * 10) + (str[i] - '0');  
        }
        
        else if (str[i] == '+' || str[i] == '-') {
            if (operation == '+')
                result += num;  
            else if (operation == '-')
                result -= num;  
                
            operation = str[i];  
            num = 0;  
        }
        
        else {
            printf("Invalid expression: unrecognized character '%c'.\n", str[i]);
            return 0;
        }
    }
    
    
    if (operation == '+')
        result += num;
    else if (operation == '-')
        result -= num;

 
    printf("Answer: %d\n", result);
    return 0;
}
