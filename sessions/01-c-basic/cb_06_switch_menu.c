/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script is a basic calculator whith varius functions (+,-,*,/) using the switch operator and while loop.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>

int main() {
    int option = 0;
    int first_number;
    int second_number;

    printf("welcome to the calculator 2.0\n");

    while (option != 5) {
        printf("choose from the following options:\n 1. addition\n 2. substraction\n 3. multipliction\n 4. division\n 5. exit\n");
        scanf("%d", &option);

        if (option == 5) {
            break;
        }

        if (option >= 1 && option <= 4) {
            printf("Enter the first number: ");
            scanf("%d", &first_number);
            printf("Enter the second number: ");
            scanf("%d", &second_number);
        }

        switch (option) {
            case 1:
                printf("%d + %d = %d\n\n", first_number, second_number, first_number + second_number);
                break;
            case 2:
                printf("%d - %d = %d\n\n", first_number, second_number, first_number - second_number);
                break;
            case 3:
                printf("%d * %d = %d\n\n", first_number, second_number, first_number * second_number);
                break;
            case 4:
                if (second_number != 0) {
                    printf("%d / %d = %d\n\n", first_number, second_number, first_number / second_number);
                } else {
                    printf("Error: Division by zero\n\n");
                }
                break;
            default:
                printf("Invalid option. Try again.\n\n");
                break;
        }
    }

    return 0;
}