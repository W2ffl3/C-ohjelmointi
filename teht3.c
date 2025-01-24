#include <stdio.h>

int main() {
    int opiskelija;

    // Kysyy opiskelijoiden määrää.
    printf("Enter the number of students: ");
    scanf("%d", &opiskelija);

    // int array opiskelijoidenmäärän perusteella
    int arvosanat[opiskelija];

    // Kaikki luvut -1.
    for (int i = 0; i < opiskelija; i++) {
        arvosanat[i] = -1;
    }

    int opiskelijanumero, arvosana;

    // Valitse opiskelija.
    while (1) {
        printf("Enter student number (1 - %d) or 0 to stop: ", opiskelija);
        scanf("%d", &opiskelijanumero);

        // Lopettaa ohjelman.
        if (opiskelijanumero == 0) {
            break;
        }

        // Opiskelijanumeron syötetarkistus.
        if (opiskelijanumero < 1 || opiskelijanumero > opiskelija) {
            printf("Invalid student number! Please enter a number between 1 and %d.\n", opiskelija);
            continue;
        }

        // Arvostelee.
        printf("Enter grade for student %d (0-5) or -1 to skip: ", opiskelijanumero);
        scanf("%d", &arvosana);

        // Arvosanan syötetarkistus.
        if (arvosana >= -1 && arvosana <= 5) {
            arvosanat[opiskelijanumero - 1] = arvosana;
        } else {
            printf("Invalid grade! Please enter a grade (0-5) or -1 to skip.\n");
        }
    }

    // Tulostus.
    printf("\nStudent \tGrades \n");
    for (int i = 0; i < opiskelija; i++) {
        printf("%d \t \t", i + 1);
        if (arvosanat[i] == -1) {
            printf("N/A\n");
        } else {
            printf("%d\n", arvosanat[i]);
        }
    }

    return 0;
}
