#include <stdio.h>
int main()
{
	char character;
	
	printf("enter character :");
	scanf("%c",&character);
	
	if (character>=41 && character<=90){
		printf("character is a capital digit");
	}
	else if (character>=97 && character<=122){
		printf("character is a small digit");
	}
	else if (character>=48 && character<=57){
		printf("character is a digit");
    }
	else {
	printf("character is a special character");	
}
	return 0;
}
