#include <stdlib.h>
#include <stdio.h>

void fill_array(int** matrix, int dims){

    int counter = 1;

    for (int i = 0; i < dims; i++){
        for (int j = 0; j < dims; j++){
            *(*(matrix + i) + j) = counter;
            counter++;
        }
    }

}

void show_matrix(int** matrix, int dims){

    for (int i = 0; i < dims; i++){
        for (int j = 0; j < dims; j++){
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

}

#define N 3

int main(){
    
    int rows = N;
    int columns = N;

    int** matrix = (int**) malloc(rows * sizeof(int*));
    if (matrix == NULL){
        printf("Memory error");
        return 1;
    }

    for(int i = 0; i < rows; i++){
        *(matrix + i) = (int*) malloc(columns * sizeof(int));
        
        if(*(matrix + i) == NULL){
            printf("Memory error");
            return 1;
            break;
        }
    }

    //-----

    fill_array(matrix, rows);
    show_matrix(matrix, columns);

    for(int i = 0; i < rows; i++){
        free(*(matrix + i));
    }

    free(matrix);

}