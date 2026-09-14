/*
* @file cb_01_calculator.c
* @brief Implementation for understanding variables, data types, cicles, inputs/outputs.
* @details This script count the vowels number in a input.
* @author Didier Torres (DidierPrody)
* @date 13-09-2026
*/
#include <stdio.h>
#include <ctype.h>

int vowels_counter(char *str){
    int counter = 0;

    for(int i = 0; i < str[i] != '\0'; i++){
        char c = tolower((unsigned char)str[i]);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            counter++;
        }
    }

    return counter;
}

int main(){
    char text[100];

    if(fgets(text, sizeof(text), stdin)){
        int total = vowels_counter(text);
        printf("Total vowels: %d\n", total);
    }
    return 0;
}