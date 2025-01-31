#include <stdio.h>

int read_range(int low, int high);  // Read_range declaration

int main() {
    int user_roll;
    int round;

    printf("Let's play!\n");    // Game introduction prints
    printf("You will play 3 rounds. In each round, you'll roll a die (1 to 6).\n");

    for (round = 1; round <= 3; round++) {
        // Ask for a die roll
        printf("\nRound %d: Please roll the die (enter a number between 1 and 6): ", round);
        user_roll = read_range(1, 6);

        if (user_roll == 6) {   // Check if 6 and claim victory
            printf("You rolled a 6! I rolled a 6. It's a tie!\n");
        } else {
            printf("You rolled a %d. I rolled a %d. I win.\n", user_roll, user_roll + 1);
        }
    }

    printf("\nBetter luck next time!\n");
    return 0;
}

int read_range(int low, int high) {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) { // Check if the input is an integer
            while (getchar() != '\n');  // Clear buffer
            printf("Invalid input. Please enter a number between %d and %d: ", low, high);
        } else if (input < low || input > high) { // Check input range
            printf("Invalid input. Please enter a number between %d and %d: ", low, high);
        } else {
            return input;
        }
    }
}
