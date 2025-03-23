#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu();
int getUserChoice();
void rollD6();
void rollD10();

int main() {
    int choice;

    srand(time(0));

    do {
        printMenu();  // Menu
        choice = getUserChoice();  // Choice

        switch (choice) {
            case 1:
                rollD6();  // Roll D6
            break;

            case 2:
                rollD10(); // Roll D10
            break;

            case 3:
                printf("Thank you for playing. Goodbye!\n");
            break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
            break;
        }
    } while (choice != 3); // Check if 3 (exit)

    return 0;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Roll D6 (1-6)\n");
    printf("2. Roll D10 (1-10)\n");
    printf("3. Quit\n");
    printf("Please select an operation (1-3): ");
}

int getUserChoice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        while(getchar() != '\n')
        choice = 0;
    }
    return choice;
}

void rollD6() {
    int roll = (rand() % 6) + 1;  // Roll 1-6
    printf("You rolled a D6: %d\n", roll);
}

void rollD10() {
    int roll = (rand() % 10) + 1;  // Roll 1-10
    printf("You rolled a D10: %d\n", roll);
}
