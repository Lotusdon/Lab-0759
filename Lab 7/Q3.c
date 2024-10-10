#include <stdio.h>
int main ()
{
 char arr[5];
 int len;
 char *ptr = arr;
 
 printf("enter string : ");
 scanf("%s",arr);
 
 do {
 
 len++;
 ptr++;
}
 while (*ptr!='\0');
 
 printf("length is : %d\n",len);
 printf("after reversing\n");
 
 for ( int i =len ; i>=0;i--)
 {
 	printf("%c",arr[i]);
 }

}
