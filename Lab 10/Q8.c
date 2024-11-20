#include <stdio.h>

int linearSearch(int a[], int index, int size, int target)
{
    if (index == size)
    {
        return -1;
    }

    if (a[index] == target)
    {
        return index;
    }
    else
    {
        return linearSearch(a, index + 1, size, target);
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

    int val;
    printf("Enter the value to be searched: ");
    scanf("%d", &val);

    int answer = linearSearch(arr, 0, num, target);
    if (answer == -1)
    {
        printf("Value was not found in the array");
    }
    else
    {
        printf("Value was found at index %d of the array", answer);
    }

    return 0;
}

