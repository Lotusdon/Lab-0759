#include <stdio.h>

int main() 
{
    char ctype, manual;
    int dcup;
    
    printf("Enter 'B' for Black Coffee\n'W' for White Coffee: ");
    scanf(" %c", &ctype);
    if (ctype != 'B' && ctype != 'W')
    {   
        printf("Invalid Coffee Type");
        return 0;
}
    
    printf("Enter '1' for Double Size\n'0' for no Double Size: ");
    scanf("%d", &dcup);
    
     if (dcup != 0 && dcup != 1) 
     {
        printf("Invalid Entry Cup Size\n");
        return 0;
    }
    
    printf("Enter 'Y' for Manual Coffe\n'N' for automatic Coffee: ");
    scanf(" %c", &manual);

    float water = (ctype == 'W') ? 15 : 20;
    float sugar = (ctype == 'W') ? 15 : 20;
    float mix1 = (ctype == 'W') ? 20 : 25;
    float cof = (ctype == 'W') ? 2 : 15;
    float milk = (ctype == 'W') ? 4 : 0;
    float mix2 = (ctype == 'W') ? 20 : 25;

    if (dcup == 1) {
        water *= 1.5;
        sugar *= 1.5;
        mix1 *= 1.5;
        cof *= 1.5;
        milk *= 1.5;
        mix2 *= 1.5;
    }
    
    printf("Put water: %.2f mins\nSugar: %.2f mins\nMix well: %.2f mins\nAdd Coffee: %.2f mins\nAdd Milk: %.2f mins\nMix well: %.2f mins", water, sugar, mix1, cof, milk, mix2);
    
    return 0;
}
