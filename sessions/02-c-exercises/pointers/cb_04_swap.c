#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
    int var = *a;
    *a = *b;
    *b = var;
}

int main(){

    int a = 1; 
    int b = 2;

    int* p_a = &a;
    int* p_b = &b;
    
    printf("Before\n");
    printf("a = %d b = %d\n", *p_a, *p_b);

    swap(p_a, p_b);

    printf("After\n");
    printf("a = %d b = %d\n", *p_a, *p_b);



}
