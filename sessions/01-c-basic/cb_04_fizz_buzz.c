/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script evaluates the numbers from 1 to 100 with conditionals using the mod operator for print 'Fizz', 'Buzz' or 'FizzBuzz'.
* @author Didier Torres (DidierPrody)
* @date 09-09-2026
*/
#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            continue;
        }
    }
    return 0;
}