#include <stdio.h>
int main ()
{
	int temp;
	int arr[6];
	
	for (int i = 0; i<6;i++){
		printf("enter input %d : ",i+1);
		scanf("%d",&arr[i]);
}
printf("before shift\n");
for (int y = 0; y<6;y++){
		printf("%d\n",arr[y]);
		
}
temp=arr[5];
for (int x = 5; x>0;x--){
		arr[x]=arr[x-1];

}
arr[0]=temp;
printf("after shift\n");

for (int z = 0; z<6;z++){
		printf("%d\n",arr[z]);
	
}
}
