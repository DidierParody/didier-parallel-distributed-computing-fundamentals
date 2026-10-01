/*
* @author Didier Torres (Dipper)
* @date 22-09-2026
* @file cb_02_pointer_sum.c
* @brief This script makes  a dinamic array, fill it with a function(fill_array) and calculates its sum.
*/

#include <stdlib.h>
#include <stdio.h>

#define N 10

int sum_array(int *arr, int size){
    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += *(arr + i);
    }

    return sum;
}

void fill_array(int* arr, int size){
    
    for (int i = 0; i < size; i++){
        *(arr + i) = i+1;
    }
}

int main(){


    int size = N;
    int* arr = (int*) malloc(size * sizeof(int));
    
    if (arr == NULL){
        printf("Memory error");
        return 0;
    }

    
    fill_array(arr, size);

    
    int result = sum_array(arr, size);

    
    printf("result = %d\n", result);

    
    free(arr);

}