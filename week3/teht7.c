#include <stdio.h>
#include <stdbool.h>


bool read_positive(int *value) {
    printf("Enter a positive number: ");
    // Read input
    if (scanf("%d", value) == 1 && *value > 0) {
        return true;
    }
    while (getchar() != '\n')
    return false;
}

int main() {
    int guess;
    int incorrectAttempts = 0;
    bool validInput;

    printf("Guess how much money I have: \n");

    while (incorrectAttempts < 3) {

        validInput = read_positive(&guess);

        if (!validInput) {
            printf("Invalid input. Please enter a positive number.\n");
            incorrectAttempts++;
        } else {
            printf("You guessed: %d\n", guess);
            int newAmount = guess * 2 + 20;
            printf("You didn't get it right. I have %.2d euros.\n", newAmount);
        }
    }

    printf("Game over! You've made 3 incorrect attempts.\n");

    return 0;
}
