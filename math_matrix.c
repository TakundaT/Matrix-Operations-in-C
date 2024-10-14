// CODE: include necessary library(s)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    srand(time(NULL)+3);
    // Check if the number of arguments is correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    //  Terminal arguments
    //first arg is the executable file itsel
    int nrows_A=atoi(argv[1]); //second arg (no.rows of A)
    int ncols_A=atoi(argv[2]); //third arg (no.cols of A)
    int nrows_B=atoi(argv[3]); //fourth arg (no.rows of B)
    int ncols_B=atoi(argv[4]); //fifth arg (no.cols of B)
    char *operation = argv[5]; //6th arg (operation), array of string so we have to use pointer
    /*
    if no.arguments =7 and 7th argument is 'print' then set print to true, otherwise false*/
   int print = 0; // Initialize print variable to 0 (false), meaning not print

    if (argc == 7 && strcmp(argv[6], "print") == 0) {
        print = 1; // Set print to 1 (true) if count is 7 and argv[6](item at 7) is "print" meaning the answer should beprinted
    }
    double A[nrows_A][ncols_A];
    double B[nrows_B][ncols_B];
    double answer[nrows_A][ncols_B];
    double x[nrows_A][ncols_B];

   srand(time(NULL));
   generateMatrix(nrows_A, ncols_A, A);

// offset seed fot B so matrice produced arent the same
   srand(time(NULL)+63636);
   generateMatrix(nrows_B, ncols_B, B);
    
     if (strcmp(operation, "add") == 0) { //compare string arg to add
    if (nrows_A != nrows_B || ncols_A != ncols_B) {
        printf("Addition between these two matrices can't be done as they don't have the same dimensions.\n"); //print add answer if T, message if F
        return 1;
    }
    addMatrices(nrows_A, ncols_A, A, nrows_B, ncols_B, B, answer);
    }   else if (strcmp(operation, "subtract") == 0) { //same for subtract
    if (nrows_A != nrows_B || ncols_A != ncols_B) {
        printf("Subtraction between these two matrices can't be done as they don't have the same dimensions.\n");
        return 1;
    }
    subtractMatrices(nrows_A, ncols_A, A, nrows_B, ncols_B, B, answer);
    } else if (strcmp(operation, "multiply") == 0) { //same for mult
    if (ncols_A != nrows_B) {
        printf("Multiplication between these two matrices can't be done as the number of columns of the first matrix doesn't match the number of rows of the second matrix.\n");
        return 1;
    }
    multiplyMatrices(nrows_A, ncols_A, A, nrows_B, ncols_B, B, answer);
    } else if (strcmp(operation, "solve") == 0) { //same for solve
        solveLinearSystem(nrows_A, ncols_A, A, nrows_B, ncols_B, B, x);
    } else {
    printf("That operation isn't recognised, please use add, subtract, multiply, or solve.\n");
    return 1;
}


    // print matrices and the answer if print is at the end of the terminal inpt
    if (print) {
        printf("Matrix A:\n");
        printMatrix(nrows_A, ncols_A, A);
        printf("Matrix B:\n");
        printMatrix(nrows_B, ncols_B, B);
       if (strcmp(operation, "add") == 0) { //string compare to add true
        printf("Result of A + B:\n");
        } else if (strcmp(operation, "subtract") == 0) { //string compare to subtract true
            printf("Result of A - B:\n");
        } else if (strcmp(operation, "multiply") == 0) { //string compare to multiply true
            printf("Result of A * B:\n");
        } else if (strcmp(operation, "solve") == 0) { //string compare to solve true
            printf("Result of x=B/A:\n");
        } else {
            printf("That operation isn't recognised, please use add , subtract, multiply or solve.\n");
            return 1;
        }

        // Print the actual answer based on chosen operation: //var for solve is x, but for others it's answer
        if (strcmp(operation,"solve")==0){
            printMatrix(nrows_A, ncols_B, x);
        }
        else{
             printMatrix(nrows_A, ncols_B, answer);
        }
        return 0;
}}