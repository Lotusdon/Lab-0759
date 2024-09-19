#include <stdio.h>

int main() {
    int fatgram,calories,calavg,fat;
    printf("enter calories ");
    scanf("%d",&calories);
    printf("enter  fat in grams in food");
    scanf("%d",&fatgram);
    if (calories >0 && fatgram >0)
    
    {
        fat = fatgram*9;
        if (calories <= fat)
        {
        calavg=fat/calories;
        printf(" your calories percentage are %d",calavg);
        }
        else {printf("the number of calories from fat cannot be greater than the total number of calories.");}
    }
    else {printf(" calories and fat gram in food cannot be less than 0");}
}
