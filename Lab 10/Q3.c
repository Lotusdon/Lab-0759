#include <stdio.h>

#define max 50

void temp(float temp)
{
    static int count = 0;
    if (temp > max)
    {
        count++;
        printf("Temperature %.2f has exceeded the limit of temperature of %d.Limit has been exceeded %d times.\n", temp, max, count);
    }
    else
    {
        printf("Temperature %.2f is within the limit of %d.\n", temp, max);
    }
}
int main()
{
    float temp;
    char choice;
    do
    {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp);
        temp(temp);
        printf("Do you want to enter temperature again? ('Y' for yes, 'N' for no): ");
        scanf(" %c", &choice);
    } while (choice == 'Y');

    return 0;
}

