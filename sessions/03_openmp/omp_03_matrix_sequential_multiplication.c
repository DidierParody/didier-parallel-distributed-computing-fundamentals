/*
* @author Didier Torres (Dipper)
* @date 29-09-2026
* @file omp_03_matrix_sequential_multiplication.c
* @brief This script multiplies two NxN matrices (C = A * B) sequentially and measures the execution time with clock().
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main() {

    int size = N;

    // Allocate memory
    int **A = malloc(size * sizeof(int *));
    int **B = malloc(size * sizeof(int *));
    int **C = malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        A[i] = malloc(size * sizeof(int));
        B[i] = malloc(size * sizeof(int));
        C[i] = malloc(size * sizeof(int));
    }

    // Initialize matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = 1;
            B[i][j] = 2;
            C[i][j] = 0;
        }
    }

    // Start measuring execution time
    clock_t start = clock();

    // Sequential matrix multiplication
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Stop measuring execution time
    clock_t end = clock();

    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Result C[0][0]: %d\n", C[0][0]);
    printf("Sequential execution time: %f seconds\n", execution_time);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }

    free(A);
    free(B);
    free(C);

    return 0;
}