#include <stdio.h>
int main() {

char x;
for (x=0;x<6;x++){
if (x == 0 || x ==5 )
  printf("%c %c %c %c %c\n",x+65,x+66, x+67,x+68,x+69);
  else{
  	printf("%c       %c\n",x+65, x+69);
  }
	}
	

return 0;
}
