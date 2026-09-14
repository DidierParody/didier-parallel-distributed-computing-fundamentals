/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script evaluates the numbers from 1 to 100 with conditionals using the mod operator and  nested for loop to determine if number is prime.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>

int main() {
    for (int i = 2; i <= 100; i++) {
        int is_prime = 1; 

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0; 
                break;     
            }
        }

        if (is_prime) {
            printf("%d\n", i);
        }
    }

    return 0;
}