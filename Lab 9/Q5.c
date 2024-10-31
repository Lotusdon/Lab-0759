#include <stdio.h>
#include <string.h>
void rev(char arr[]){

 int start = 0;                   
   int end = strlen(arr) - 1;      

    while (start < end) {
       
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

       
        start++;
        end--;
    }
}


int main() {
    int i=0;
    
   char arr[10];
   
   printf("Enter string: ");
   scanf("%s",arr);
   rev(arr);
   printf("Reversed String:\n");
   while(arr[i]!='\0'){
   	printf("%c",arr[i]);
   	i++;
   }
   
}
