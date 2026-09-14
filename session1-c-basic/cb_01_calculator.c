/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, inputs/outputs.
* @details This script read two int numbers for perform the next operations: +,-,*,/. 
* @author Didier Torres (DidierPrody)
* @date 08-09-2026
*/

#include <stdio.h>
void calculator(int number_1, int number_2, char operator) {

    switch (operator)
    {
    case '+':
        printf("%d + %d = %d\n", number_1, number_2, number_1 + number_2);
        break;
    case '-':
        printf("%d - %d = %d\n", number_1, number_2, number_1 - number_2);
        break;
    case '*':
        printf("%d * %d = %d", number_1, number_2, number_1 * number_2);
        break;
    case '/':
        printf("%d / %d = %d", number_1, number_2, number_1 / number_2);
        break;

    default:
        printf("invalid option.");
        break;
    }

}

int main() {
    int number_1;
    int number_2;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &number_1);

    printf("Enter the second number: ");
    scanf("%d", &number_2);

    printf("Enter the operator (+,-,*,/): ");
    scanf( " %c", &operator);

    calculator(number_1,number_2,operator);

    return 0;
}