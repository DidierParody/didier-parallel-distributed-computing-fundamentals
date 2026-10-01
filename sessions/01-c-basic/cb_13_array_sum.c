#include <stdio.h>
#include <stdlib.h>

int sum_array(const int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int size = 5;
    int *array = (int *) malloc(size * sizeof(int));

    if (array == NULL) {
        return 1;
    }

    *(array + 0) = 10;
    *(array + 1) = 20;
    *(array + 2) = 30;
    *(array + 3) = 40;
    *(array + 4) = 50;

    int total = sum_array(array, size);

    printf("Array sum: %d\n", total);

    free(array);
    return 0;
}