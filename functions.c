#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Function to generate a random matrix
void generateMatrix(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Generate random numbers between -10 and 10
            matrix[i][j] = -10.0 + ((double)rand() / RAND_MAX) * 20.0;
        }
    }
}
void printMatrix(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) { //iterate through the rows of a matrix
        for (int j = 0; j < cols; j++) { //iterate through the columns of a matrix
            printf("%.2f\t", matrix[i][j]); //print the value at that specific row/column index with 2 decimal places
        }
        printf("\n");
    }
}
void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double answer[N1][M1]) {
    //two matrices must have the same dimensions fot them to be added
    //rows of marix 1 must equal rows of matrix 2  and likewise for columns
    if (N1 != N2 || M1 != M2){
        printf("Addition between these two matrices can't be done as they don't have the same dimensions.\n");
    }else{
    
    for (int row=0; row < N1; row++){ //iterate through rows
        for (int column =0; column< M1; column ++){ //iterate through columns
            answer[row][column]=A[row][column]+B[row][column]; //add corresponding row,column values between the two matrices
        }
    }
}
}

void subtractMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double answer[N1][M1]) {
    //two matrices must have the same dimensions fot them to be subtracted
    //rows of marix 1 must equal rows of matrix 2  and likewise for columns
    if (N1 != N2 || M1 !=M2){
        printf("Subtraction between these two matrices can't be done as they don't have the same dimensions.\n");
    }else{
    
    for (int row=0; row < N1; row++){ //iterate throgh rows
        for (int column =0; column< M1; column ++){ //iterate through columns
            answer[row][column]=A[row][column]-B[row][column]; //subtract corresponding row,column values between the two matrices
        }
    }
}
}
void multiplyMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double answer[N1][M2]) {
    if ( M1 != N2){
        //rule for multiplication:only when (m*n)*(n*p)
        printf("Matrix multiplication can't be done between these two matrices. The number of columns in matrix A must equal the number of rows in matrix B.\n");
    }else{
    
    for (int row =0; row<N1; row++){ //iterate through rows
        for (int column = 0; column <M2; column ++){ //iterate through columns
            answer[row][column]=0;
            for (int index = 0; index<M1; index++){ //iterate over common index when row of A= column of B
                answer[row][column] += A[row][index]*B[index][column]; 
            }
        }
    }
}
}
// Function to solve a system of linear equations Ax = B using Gaussian elimination
//The following code was inspired by chatGPT
void solveLinearSystem(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double x[N1][M2])
{
    // Make the coefficient matrix using A and B
    double coefficient[N1][M1+1];
    //coefficient matric is made by combining rows of A dn B
    for (int row = 0; row < N1; row++) 
    {
        //Ccopyelements from A to coefficient
        for (int rowvar = 0; rowvar < M1; rowvar++) 
        {
            coefficient[row][rowvar] = A[row][rowvar]; 
        }
    }
    // same for B
    for (int row = 0; row < N1; row++) 
    {
        coefficient[row][M1] = B[row][0];
    }
    
    // diagonals can't be 0, will lead to div by 0 error
    for(int row = 0 ; row < N1; row++)
    {
        // Check if the diagonal element is zero
        double buffer = coefficient[row][row];
        for(int rowvar = 0; rowvar < M1+1; rowvar++)
        {
            if(buffer == 0)
            {
                // swap rows with row below if diag element =0
                for(int colvar = row+1; colvar < N1; colvar++)
                {
                    if(coefficient[colvar][row] != 0)
                    {
                        // Swap rows
                        for(int swap = 0; swap < M1+1; swap++)
                        {
                            double holder = coefficient[row][swap];
                            coefficient[row][swap] = coefficient[colvar][swap];
                            coefficient[colvar][swap] = holder;
                        }
                        break;
                    }
                }
            }
        }
    }
    
    // make coefficient upper triangular
    for(int row = 0; row < N1; row++) 
    { 
        for(int rowvar = 0; rowvar < N1; rowvar++) 
        { 
            if(row != rowvar) 
            { 
                // Compute the factor which will subtract rows
                double scale = coefficient[rowvar][row] / coefficient[row][row];
                // Subtract current row multiplied by factor from other rows
                for(int colvar = 0; colvar <= M1; colvar++) 
                { 
                    coefficient[rowvar][colvar] -= scale * coefficient[row][colvar];
                }
            }
        }

        // Normalize pivot row/divide by pivot
        double pRow = coefficient[row][row];
        for(int colvar = 0; colvar <= M1; colvar++) 
        {  
            coefficient[row][colvar] /= pRow;
        }
    }
    
    // solution is last column in coefficient
    for(int row = 0; row < N1; row++)
    {
        x[row][0] = coefficient[row][M1];
    }
}



