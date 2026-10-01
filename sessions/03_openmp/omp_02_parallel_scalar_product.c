/*
* @author Didier Torres (Dipper)
* @date 23-09-2026
* @file omp_02_parallel_scalar_product.c
* @brief This script makes two dynamic vectors of N integers, fills them with a function (fill_array) and calculates their scalar (dot) product in parallel with OpenMP (reduction).
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define N 100000000

void fill_array(int* arr, int size){

    for (int i = 0; i < size; i++){
        *(arr + i) = i+1;
    }

}

int main(){

    int size = N;

    long long sum = 0;

    int* a_vector = (int*) malloc(size * sizeof(int));

    int* b_vector = (int*) malloc(size * sizeof(int));

    if (a_vector == NULL || b_vector == NULL){
        printf("Memory error");
        return 1;
    }

    fill_array(a_vector, size);
    fill_array(b_vector, size);

    double start = omp_get_wtime();

    #pragma omp parallel 
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        printf("Thread %d of %d\n", thread_id, total_threads);
    

    #pragma omp parallel for reduction(+:sum)
    for( int i = 0; i < size; i++){



        sum+= *(a_vector + i) * *(b_vector + i);

    }
}

    double elapsedtime = omp_get_wtime() - start;

    printf("Parallel time = %.3f\n", elapsedtime);
    printf("Sum = %lld\n", sum);


    free(a_vector);
    free(b_vector);

    return 0;
}