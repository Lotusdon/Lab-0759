#include <stdio.h>
int main ()
{
 char arr[10];
 int len;
 char *ptr = arr;
 int palindrome=0;
  
 printf("enter string : ");
 scanf("%s",arr);
 
 do {
 
 len++;
 ptr++;
}
 while (*ptr!='\0');
    
    for(int i = 0; i < len/2; i++) {
        if(arr[i] == arr[len-i-1]){
            palindrome = 1;
        }
        else{
            palindrome = 0;
            break;
        }
    }
    
    if (palindrome == 1) {
        printf("This string is a palindrome\n");
    }
    else {
       printf("This string is not a palindrome\n"); 
    }
    return 0;
}
