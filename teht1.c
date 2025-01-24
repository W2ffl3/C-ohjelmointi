#include <stdio.h>

int main() {
    float bussi, taxi, raha;
    int choice;

    printf("Enter the price of a bus ticket: ");
    scanf("%f", &bussi);

    printf("Enter the price of a taxi trip: ");
    scanf("%f", &taxi);

    printf("Enter how much money you have: ");
    scanf("%f", &raha);

    while (1) {
        if (raha < bussi && raha < taxi) {
            printf("You don't have enough money for either the bus or the taxi. You should walk.\n");
            break;
        }

        printf("Choose your transportation: \n");
        printf("1. Bus \n");
        printf("2. Taxi \n");
        printf("Enter 1 for Bus or 2 for Taxi: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (raha >= bussi) {
                raha -= bussi;
                printf("You chose the bus. You have %.2f left.\n", raha);
            } else {
                printf("You don't have enough money for the bus.\n");
            }
        } else if (choice == 2) {
            if (raha >= taxi) {
                raha -= taxi;
                printf("You chose the taxi. You have %.2f left.\n", raha);
            } else {
                printf("You don't have enough money for the taxi.\n");
            }
        } else {
            printf("Invalid choice. Please choose 1 for bus or 2 for taxi.\n");
            continue;
        }

        if (raha < bussi && raha < taxi) {
            printf("You don't have enough money for either the bus or the taxi. You should walk.\n");
            break;
        }
    }

    return 0;
}
