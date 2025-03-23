#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array, unsigned int what) {
    int index = 0;
    while (array[index] != 0) {
        if (array[index] == what) {
            return index;
        }
        index++;
    }
    return -1;
}

int main() {
    unsigned int array[20];
    srand(time(NULL));

    for (int i = 0; i < 19; i++) {
        array[i] = rand() % 20 + 1;
    }
    array[19] = 0;

    // Print array
    printf("Array elements:\n");
    for (int i = 0; i < 20; i++) {
        printf("%u\n", array[i]);
    }

    unsigned int number;
    int result;

    while (1) {
        printf("\nEnter a number to search for (or 0 to stop): ");
        scanf("%u", &number);

        if (number == 0) {
            break;  // Exit loop if input 0
        }

        result = find_first(array, number);

        if (result == -1) {
            printf("Number not found.\n");
        } else {
            printf("Number found at index: %d\n", result);
        }
    }

    return 0;
}
