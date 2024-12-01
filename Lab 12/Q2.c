#include <stdio.h>


void swaped(int *aPtr,int *bPtr,int *cPtr){
int temp = *bPtr;
*bPtr=*aPtr;
*aPtr=*cPtr;
*cPtr=temp;
}
int main() {
    int a,b,c;
  printf("Enter value for first variable : ");
  scanf("%d",&a);
  printf("Enter value for second variable : ");
  scanf("%d",&b);
  printf("Enter value for third variable : ");
  scanf("%d",&c);
  swaped(&a,&b,&c);
    
printf("after swapping\n");
   printf("first variable value : %d\n",a);
  printf("second variable value : %d\n",b);
  printf("third variable value : %d\n",c);
    return 0;
}
