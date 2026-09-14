#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person people[3] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 22}
    };

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    return 0;
}