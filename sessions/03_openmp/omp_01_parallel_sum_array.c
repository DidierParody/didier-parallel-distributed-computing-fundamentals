/*
* @author Didier Torres (Dipper)
* @date 23-09-2026
* @file omp_01_parallel_sum_array.c
* @brief This script makes a dynamic array of N integers, fills it with a function (fill_array) and calculates its sum in parallel with OpenMP (parallel for + reduction).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 100000000

void fill_array (int* arr, int size){
    for (int i = 0; i < size; i++){
        *(arr + i) = i + 1;
    }
}
int main(){

    int size = N;

    int* arr = (int*) malloc(size * sizeof(int));

    int sum = 0;
    

    if (arr == NULL){
        printf("Memory error");
        return 1;
    }

    fill_array(arr, size);

    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; i++){
        sum += *(arr + i);
    }

    double elapsedtime = omp_get_wtime() - start;

    printf("Parallel time: %.6f\n", elapsedtime);
    printf("Sum: %d\n", sum);

    return 0;
}
