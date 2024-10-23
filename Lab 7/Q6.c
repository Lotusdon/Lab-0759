#include <stdio.h>

int main()
{
    int n;
    printf("Enter Array size: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > high)
        {
            high = arr[i];
        }
    }

    int freq[high];
  
    for (int i = 0; i <= high; i++)
    {
        freq[i] = 0;
    }
   
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i <= high; i++)
    {
        if (freq[i] > 1)
            printf("Number %d occurs more than once\n", i);
    }

    return 0;
}
