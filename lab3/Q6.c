#include <stdio.h>
int main() 
{ 
int x1,x2,y1,y2;
float slope;
printf(" enter x coordinate of point A : ");
scanf("%d",&x1);
printf(" enter y coordinate of point A : ");
scanf("%d",&y1);
printf(" enter x coordinate of point B : ");
scanf("%d",&x2);
printf(" enter y coordinate of point B : ");
scanf("%d",&y2);

slope = (y2-y1)/(x2-x1);
printf(" Slope of the points are %.3f",slope);
return 0;
}