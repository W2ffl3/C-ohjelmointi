#include <stdio.h>

int read_integer(void) {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) {
            return num;
        }

        printf("Invalid input\n");
        printf("Enter positive number. Negative to stop: ");

        while (getchar() != '\n');
    }
}

int main() {
    int sum = 0, count = 0, number = 0;

    printf("Enter positive number. Negative to stop: ");

    while (1) {
        number = read_integer();

        if (number < 0) {
            break;
        }

        sum += number;
        count++;

        printf("Enter positive number. Negative to stop: ");
    }

    if (count > 0) {
        double average = (double)sum / count;
        printf("You entered %d positive numbers. The average is: %.3f\n", count, average);
    } else {
        printf("No positive numbers entered.\n");
    }

    return 0;
}
