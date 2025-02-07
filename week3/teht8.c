#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]); // Print numbers in 8 character field
    }
}

int main() {
    // 15 integer array
    int numbers[15];

    // random number seed
    srand(time(NULL));

    // randomize integers in array
    for (int i = 0; i < 15; i++) {
        numbers[i] = rand() % 1000;
    }

    // call print_numbers function
    print_numbers(numbers, 15);

    return 0;
}
