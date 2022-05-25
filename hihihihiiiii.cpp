#include <stdio.h>
#include <conio.h>
const int MAX = 100;
void input(int matrix1[MAX][MAX], int row, int col);
void output(int matrix1[MAX][MAX], int row, int col);
void addMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int additionMatrix[MAX][MAX], int r1, int c1, int r2, int c2);
int main(){
    int matrix1[MAX][MAX], matrix2[MAX][MAX], additionMatrix[MAX][MAX];
    int r1, c1, r2, c2, ar, ac;
    do{
        printf("Input row of matrix 1: ");
        scanf("%d", &r1);
        printf("Input column of matrix 1: ");
        scanf("%d", &c1);
        input(matrix1, r1, c1);
        printf("Matrix 1: ");
        output(matrix1, r1, c1);
        printf("Input row of matrix 2: ");
        scanf("%d", &r2);
        printf("Input column of matrix 2: ");
        scanf("%d", &c2);
        input(matrix2, r2, c2);
        printf("Matrix 2: ");
        output(matrix2, r2, c2);
    }while(r1 != r2 || c1 != c2);
        printf("Input again");
    printf("\nAddition of two matrix is: %d\t", additionMatrix[i][j]);
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c1; j++) {
         printf("%d\t", matrix3[i][j]);
    getch();
    return 0;
}
void input(int matrix1[MAX][MAX], int row, int col){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            printf("Input matrix: %d, %d, i, j");
            scanf("%d", &matrix1[i][i]);
        }
    }
}
void output(int matrix1[MAX][MAX], int row, int col){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}
void addMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int additionMatrix[MAX][MAX], int r1, int c1, int r2, int c2){
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) {
        additionMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
}
