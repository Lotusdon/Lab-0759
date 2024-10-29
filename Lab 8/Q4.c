#include <stdio.h>

int main() {
    int matrix[3][3] = {{2, 4, 6}, {7, 43, 67}, {1, 8, 5}};
    int matrix2[3][3] = {{2, 4, 6}, {7, 43, 67}, {1, 8, 5}};
    int result[3][3] = {0};

 
    for (int x = 0; x < 3; x++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[x][i] += matrix[x][j] * matrix2[j][i];
            }
        }
    }

 
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
