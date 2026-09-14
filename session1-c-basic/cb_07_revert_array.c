/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script create a dinamic array with malloc and revert using for loops.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int size = 10;
    int value = 0;
    int *array = (int *) malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < size; i++ ){
    printf("Enter number %d. : ", i + 1);
    scanf("%d", &value);
    *(array + i) = value;
    value = 0;
    }

    for (int j = size - 1; j >= 0; j--){
        printf("%d ", *(array + j));
    }

    return 0;
}