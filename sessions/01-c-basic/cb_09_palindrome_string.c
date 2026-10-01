/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script create a char array and create a new char dinamic array reverted.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char word[] = "Didier";
    int len = strlen(word);

    char *reversed = (char *) malloc((len + 1) * sizeof(char));

    if (reversed == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        reversed[i] = word[len - 1 - i];
    }
    reversed[len] = '\0';

    if (strcmp(word, reversed) ==0){
        printf("They are the same");
    } else {
        printf("They are not the same");
    }
    free(reversed);
    return 0;
}