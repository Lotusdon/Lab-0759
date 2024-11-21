// i am assuming the file is properly formatted . I will then decalre a struct .Open file and read each line into their records and then compare with the word to be searched. If found the count is increased.


#include <stdio.h>
#include <string.h>

typedef struct {
	char name[10];
	int id;
	int marks;
}y;

int main(){
	y x;
	FILE *f1ptr;
	int count=0,i;
	char buffer[50];

	f1ptr= fopen("11.txt","r");
	
	
	
	
	
	while((fgets(buffer,sizeof(buffer),f1ptr)!=NULL)){
		fscanf(f1ptr,"%s %d %d",x.name,&x.id,&x.marks);
		if (strcmp(entry.name, "word") == 0) {
        count++; 
        }
		
		
	}
	fclose(f1ptr);
	printf("count of word is %d",count);
	
}
