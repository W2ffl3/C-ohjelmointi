#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to find the first time a number is found in the array
int find_first(const unsigned int *array, unsigned int what) {
    int index = 0;
    while (array[index] != 0) { // stop when zero is encountered
        if (array[index] == what) {
            return index; // Return the index if number is found
        }
        index++;
    }
    return -1; // Return -1 if the number is not found
}

int main() {
    unsigned int array[20];       // Array for 20 integers
    srand(time(NULL));       // Random number seed

    // Fill the array with random numbers between 1 and 20 with 0 at the end.
    for (int i = 0; i < 19; i++) {
        array[i] = rand() % 20 + 1;
    }
    array[19] = 0;  // Mark the end of the array with zero

    // Print array
    printf("Array elements:\n");
    for (int i = 0; i < 20; i++) {
        printf("%u\n", array[i]);
    }

    unsigned int number;  // Variable to store the number to search
    int result;

    // Loop to ask the user for numbers to search for
    while (1) {
        printf("\nEnter a number to search for (or 0 to stop): ");
        scanf("%u", &number);

        if (number == 0) {
            break;  // Exit loop if input 0
        }

        // Call find_first function
        result = find_first(array, number);

        if (result == -1) {
            printf("Number not found.\n");
        } else {
            printf("Number found at index: %d\n", result);
        }
    }

    return 0;
}
