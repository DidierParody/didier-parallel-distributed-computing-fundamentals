/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, inputs/outputs.
* @details This script read one float number for perform the conversion from celsiud to fahrenheits using the next formula '(celsius * 9/5) + 32'. 
* @author Didier Torres (DidierPrody)
* @date 08-09-2026
*/
#include <stdio.h>
float celsius_to_fahrenheit(float celsius) {

    return (celsius * 1.8) + 32;

}

int main(){

    float celsius;

    printf("Enter celsius: ");
    scanf("%f", &celsius);

    printf("Fahrenheits: %2.f", celsius_to_fahrenheit(celsius));
}