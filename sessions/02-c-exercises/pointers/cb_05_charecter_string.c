#include <stdlib.h>
#include <stdio.h>

int main(){
    char character_string[3] = "hi";
    char* p_character_string = character_string;

    for (int i = 0; i < sizeof(character_string); i++){
        printf("character: %c; memory: %p\n", *(p_character_string + i), (void*)(p_character_string + i));
    }
    
}