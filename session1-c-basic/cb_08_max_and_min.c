
/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script find the max and min value in an array.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>
#include <stdlib.h>
int find_minor(int *array, int size){
        
    int minor;
    for (int j = 0; j < size; j++){
        if (j == 0) {
            minor = *(array + j);
        }
        for (int k = 0; k <= j; k++){
            if (*(array + k) < minor){
                minor = *(array + k);
            }
        }
        
        }

        return minor;
    }

int find_largest(int *array, int size){
        
    int largest;
    for (int j = 0; j < size; j++){
        if (j == 0) {
            largest = *(array + j);
        }
        for (int k = 0; k <= j; k++){
            if (*(array + k) > largest){
                largest = *(array + k);
            }
        }
        
        }

        return largest;
    }

 int main(){

    int size = 5;
    int *array = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++){
        *(array + i) = i;
    }

    for (int number = 0; number < size; number ++){
        printf("%d ", *(array + number));
    }

    int minor = find_minor(array, size);
        printf("\nthe minor is: %d", minor);

    int largest = find_largest(array, size);
    printf("\nthe largest is: %d", largest);
    
        return 0;
    }
