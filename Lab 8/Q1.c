#include <stdio.h>
int main() {
    int s , e , i =0 , j=0 ;
    printf("Enter Start range: ");
    scanf("%d", &s);
    printf("Enter End range: ");
    scanf("%d", &e);
    
    printf("Prime number series\n");
    for(int i = s ; i <= e ; i++){
        for (int j = i-1 ; j >=2 ; j--){
            if(i%j == 0 ) {
                break;  
            }
            if(j==2 && i%j != 0 ){
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
