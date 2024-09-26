#include <stdio.h>

int main() 
{

int ph;
printf("Enter pH level: ");
scanf("%d", &ph);
if (ph > 14) 
{
printf("Invalid Input!");
}
else if (ph > 7) 
{
      if (ph < 12) { 
      printf("Alkaline");
      } 
      else 
      {
      printf("Very Alkalaine");\
      }
}
else if (ph == 7) 
{
      printf("Neutral");
}
else if (ph > 2) {
      printf("Acidic");
}
else 
{
      printf("Very Acidic");
}
return 0;
}
