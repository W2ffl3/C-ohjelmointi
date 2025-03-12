#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int userInput;
    srand(time(0));

    while (1) {

        printf("Enter a number between 0 and 15 (or a negative number to stop): ");
        if (scanf("%d", &userInput) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while(getchar() != '\n');
            continue;
        }

        if (userInput < 0) {
            break;
        }

        if (userInput < 0 || userInput > 15) {
            printf("Invalid number! Please enter a number between 0 and 15.\n");
            continue;
        }

        int randomNum = rand();
        printf("Generated random number: 0x%X\n", randomNum);

        int shiftedNum = randomNum >> userInput;

        int maskedNum = shiftedNum & 0x3F;

        printf("Result after shift and mask: 0x%02X\n", maskedNum);
    }

    printf("Program stopped.\n");

    return 0;
}
