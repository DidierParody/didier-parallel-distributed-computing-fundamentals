/*
* @author Didier Torres (Dipper)
* @date 22-09-2026
* @file omp_01_sequential_sum_array.c
* @brief This script makes a dynamic array of N integers, fills it with a function (fill_array) and calculates its sum sequentially, measuring the time with clock().
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    clock_t start, end;

    if (arr == NULL){
        printf("Memory error");
        return 1;
    }

    fill_array(arr, size);

    start = clock();

    for (int i = 0; i < size; i++){
        sum += *(arr + i);
    }

    end = clock();

    double time_spent = (double)(end-start) / CLOCKS_PER_SEC;

    printf("Sequential time: %.6f\n", time_spent);
    printf("Sum: %d\n", sum);

    return 0;
}
