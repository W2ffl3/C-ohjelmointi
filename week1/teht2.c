#include <stdio.h>
#define NUM_MONTHS 12

int main() {
    float salaries[NUM_MONTHS];
    float taxes[NUM_MONTHS];

    float taxPercentage, higherTaxPercentage, yearlyLimit;

    printf("Enter the tax percentage: ");
    scanf("%f", &taxPercentage);

    printf("Enter the yearly income limit: ");
    scanf("%f", &yearlyLimit);

    printf("Enter the tax percentage for income above the yearly limit: ");
    scanf("%f", &higherTaxPercentage);

    printf("Enter the monthly salary for each of the 12 months:\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("Month %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    for (int i = 0; i < NUM_MONTHS; i++) {
        if (salaries[i] <= yearlyLimit) {
            taxes[i] = (salaries[i] * taxPercentage) / 100;
        } else {
            taxes[i] = (yearlyLimit * taxPercentage) / 100 +
                        ((salaries[i] - yearlyLimit) * higherTaxPercentage) / 100;
        }
    }

    printf("\n Monthly \t Salaries \t \t Taxes: \n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("Month %d: \t Salary = %.2f \t Tax = %.2f\n", i + 1, salaries[i], taxes[i]);
    }

    return 0;
}
