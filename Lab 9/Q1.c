#include <stdio.h>
#include <string.h>

int main() {
    int row, column;

    printf("Enter array row number: ");
    scanf("%d", &row);
    printf("Enter array column number: ");
    scanf("%d", &column);

  
    if (column <= 0 || row <= 0) {
        printf("Invalid row or column size.\n");
        return 1;
    }

    char arr[row][column]; 


    for (int i = 0; i < row; i++) {
        printf("Enter string at row %d: ", i + 1);
        scanf("%s", arr[i]);
    }

 
    printf("\nYou entered:\n");
    for (int i = 0; i < row; i++) {
        printf("%s\n", arr[i]);
    }

   
    for (int i = 0; i < row; i++) {
        char reversed[column];
        strcpy(reversed, arr[i]); 
        strrev(reversed); 

   
        if (strcmp(arr[i], reversed) == 0) {
            printf("String at row %d is a palindrome.\n", i + 1);
        } else {
            printf("String at row %d is not a palindrome.\n", i + 1);
        }
    }

    return 0;
}
