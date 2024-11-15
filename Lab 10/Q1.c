#include <stdio.h>
int reverse(int a[],int len,int s){
    if ( len!=0){
        printf("%d",a[s]);
        reverse(a,len-1,s+1);
    }
    else {
        printf("");
    }
    
}
int main() {
   int arr[]={1,2,3,4,5};
   int length =5,start=0;
   reverse(arr,length,start);
}
