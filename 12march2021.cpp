#include<stdio.h>
#include<conio.h>
const int MAX = 100;
int main() {
    int i, j, matrix1[MAX][MAX], matrix2[MAX][MAX], matrix3[MAX][MAX];
    int row1, col1, row2, col2;
    printf("Input row of matrix1: ");
    scanf("%d", &row1);
    printf("Input column of matrix1: ");
    scanf("%d", &col1);
    printf("Input row of matrix2: ");
    scanf("%d", &row2);
    printf("Input column of matrix2: ");
    scanf("%d", &col2);
    if(row1 != row2 || col1 != col2) {
        printf("Input again!");
    return 0;
    }
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
        printf("Input element matrix1[%d][%d]: ", i, j);
        scanf("%d", &matrix1[i][j]);
        }
    }
    for (i = 0; i < row2; i++){
        for (j = 0; j < col2; j++) {
        printf("Input element matrix2[%d][%d]: ", i, j);
        scanf("%d", &matrix2[i][j]);
        }
    }
    for (i = 0; i < row1; i++){
        for (j = 0; j < col1; j++){
        matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Addition of two matrix is: \n");
    for (i = 0; i < row1; i++){
        for (j = 0; j < col1; j++){
            printf("%8d", matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
