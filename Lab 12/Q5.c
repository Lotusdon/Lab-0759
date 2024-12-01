#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main() {
    int n,len;
    char *arr;
  char *id=(char *)malloc(7*sizeof(char));
  if (id == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter total number of characters ");
    scanf("%d", &n);
  n++; // for the space between

  arr=(char*)malloc(n*sizeof(char));
  if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
  printf("enter your full name : ");
  scanf(" %[^\n]",arr);
  
   printf("your name is %s\n",arr);
  printf("enter your student id : ");
  scanf(" %[^\n]",id);
  strcat(id," ");
  len =strlen(id);
  id =(char *)realloc(id,(len+n)*sizeof(char));
  strcat(id,arr);
  printf("\n%s",id);
  
  
  
   
    free(arr);
  free(id);

    return 0;
}
