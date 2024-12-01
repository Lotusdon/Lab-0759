#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n;
    char *arr;

    printf("Enter total number of characters ");
    scanf("%d", &n);
  n++; // for the space between

  arr=(char*)malloc(n*sizeof(char));
  printf("enter your full name");
  scanf(" %[^\n]",arr);
  
   printf("your name is %s",arr);
   
    free(arr);

    return 0;
}
