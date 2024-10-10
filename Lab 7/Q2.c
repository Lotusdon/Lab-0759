#include <stdio.h>
int main ()
{
	char x;
	int ac,ec,ic,oc,uc;
	char arr[6];
	
	printf("enter string : ");
	scanf("%s",arr);
	
	for (int i = 0;i<sizeof(arr);i++){
		x=arr[i];
		switch(x){
			case 'a': ac++;
			break;
			
			case 'e': ec++;
			break;
			
			case 'i' : ic++;
			break;
			
			case 'o': oc++;
			break;
			
			case 'u' : uc++;
			break;
			
		default : break;
			
			
		}
		
	}
printf ("a count : %d , e count : %d , i count : %d , o count : %d , u count : %d",ac,ec,ic,oc,uc);
}
