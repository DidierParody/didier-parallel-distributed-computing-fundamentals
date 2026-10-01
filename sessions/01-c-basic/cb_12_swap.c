#include <stdio.h>
void swap(int* x, int* y){

    int provisional = *x;
    *x = *y;
    *y = provisional;

}
int main(){

    int x = 52;
    int y = 23;

    int* ptr_x = &x;
    int* ptr_y = &y;

    swap(ptr_x,ptr_y);
    printf(" x = %d\n", x);
    printf("y = %d\n", y);
    return 0;
}