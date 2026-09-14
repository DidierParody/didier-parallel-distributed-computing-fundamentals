/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, inputs/outputs.
* @details This script read two float numbers for create a struct to represent the rectangle, then use the functions 'area' and 'perimeter' for get both usging the following formulas:
    Perimeter = 2 (base + height), Area = base * height. 
* @author Didier Torres (DidierPrody)
* @date 08-09-2026
*/
#include <stdio.h>
typedef struct {
    float base;
    float height;
} Rectangle;

float area(Rectangle rectange) {return rectange.base * rectange.height;}

float perimeter(Rectangle rectangle) {return 2 * (rectangle.base + rectangle.height);}

int main(){
    
    Rectangle rectangle;

    printf("Enter rectangle base: ");
    scanf("%f", &rectangle.base);

    printf("Enter rectangle height: ");
    scanf("%f", &rectangle.height);

    printf("Area: %2.f m^2\n", area(rectangle));
    printf("Perimeter: %2.f m\n", perimeter(rectangle));

}