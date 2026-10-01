/*
* @author Didier Torres (Dipper)
* @date 22-09-2026
* @file cb_01_pointer_array_fill.c
* @brief This script make  a dinamic array and with a function (print_array) print it
*/

#include <stdlib.h>
#include <stdio.h>
#define N 10

void print_array(int* arr, int size){
    printf("[");
    for (int i = 0; i < size; i++){

        if (i == size){
            printf("]");
        }

        printf("%d,", *(arr + i));
    }

}

int main(){
    int size = N;
    int *arr = (int*) malloc(size * sizeof(int));

    if ( arr == NULL){
        printf("Memory error");
        return 1;
    }

    for (int i = 0; i < size; i++){

        *(arr + i) = i+1;

    }

    print_array(arr,size);

    free(arr);
    return 0;
}