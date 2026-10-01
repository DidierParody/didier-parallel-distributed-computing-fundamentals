/*
* @author Didier Torres (Dipper)
* @date 29-09-2026
* @file omp_03_matrix_parallel_multiplication.c
* @brief This script multiplies two NxN matrices (C = A * B) in parallel with OpenMP, splitting the rows of C between the threads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

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
    double start = omp_get_wtime();

    // Parallel matrix multiplication
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {

        int thread_id = omp_get_thread_num();

        printf("Thread %d is calculating row %d\n", thread_id, i);

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Stop measuring execution time
    double end = omp_get_wtime();

    printf("Result C[0][0]: %d\n", C[0][0]);
    printf("Parallel execution time: %f seconds\n", end - start);

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