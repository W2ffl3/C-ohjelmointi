#include <stdio.h>

int read_integer(void) {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) {
            return num; // Successfully read an integer
        }
        // Error handling for invalid input
        printf("Invalid input\n");
        printf("Enter positive number. Negative to stop: ");
        // Clear input buffer
        while (getchar() != '\n');
    }
}

int main() {
    int sum = 0, count = 0, number = 0;

    // Initial prompt
    printf("Enter positive number. Negative to stop: ");

    while (1) {
        number = read_integer(); // Read an integer

        if (number < 0) {
            break; // End if negative
        }

        sum += number; // Add the number to the sum
        count++; // Increment the count of positive numbers

        printf("Enter positive number. Negative to stop: ");
    }

    // Calculate and display the average
    if (count > 0) {
        double average = (double)sum / count;
        printf("You entered %d positive numbers. The average is: %.3f\n", count, average);
    } else {
        printf("No positive numbers entered.\n");
    }

    return 0;
}
