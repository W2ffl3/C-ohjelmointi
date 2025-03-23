#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}

int main() {
    int numbers[15];

    srand(time(NULL));

    for (int i = 0; i < 15; i++) {
        numbers[i] = rand() % 1000;
    }

    print_numbers(numbers, 15);

    return 0;
}
