#include <stdio.h>

void bubbleSort(int a[], int size)
{
    if (size == 1)  
    { 
        return;
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        bubbleSort(arr, size - 1);
    }
}

int main()
{
    int num;
    printf("Enter the size of the array: ");
    scanf("%d", &num);
    int arr[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter the element at %d index: ", i+1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, num);

    printf("\nSorted array:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

