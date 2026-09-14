/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script determine if a number is prime and get the set fibonacci values.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>
#include <stdbool.h>


bool is_prime(int number) {
    if (number <= 1) {
        return false; // Los números <= 1 no son primos
    }
    
    for (int i = 2; i * i <= number; i++) { 
        if (number % i == 0) {
            return false; 
        }
    }
    
    return true; 
}


void fibonacci(int limit) {
    int a = 0;
    int b = 1;

    for (int i = 0; i < limit; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int number = 5;

    
    if (is_prime(number)) {
        printf("The number %d is prime. Serie Fibonacci (%d terms):\n", number, number);
        fibonacci(number);
    } else {
        printf("The number %d is not prime.\n", number);
    }

    return 0;
}