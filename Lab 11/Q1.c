#include <stdio.h>

int main(){
	FILE *f1ptr,*f2ptr;

	f1ptr= fopen("11.txt","r");
	f2ptr= fopen("22.txt","w");
	
	char arr[10];
	
	int i;
	for ( i=0;i<4;i++){
		fscanf(f1ptr,"%s",&arr);
		fprintf(f2ptr,"%s\n",arr);
		
	}
	fclose(f1ptr);
	fclose(f2ptr);
}
