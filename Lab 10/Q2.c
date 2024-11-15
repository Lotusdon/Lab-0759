#include <math.h>
#include <stdio.h>

typedef struct{
    int x;
    int y;
}cod;

int distance( cod c1, cod c2){
    int dist;
    dist =  ((c2.x -c1.x)*(c2.x - c1.x)) + ((c2.y - c1.y)*(c2.y - c1.y));
    return dist;
}
int main() 
{
    cod p1;
    cod p2;
   p1.x=2;
   p1.y=3;
   p2.x=4;
   p2.y=5;
   printf("%d",p1.x);
   printf("%d",distance(p1,p2));
}
