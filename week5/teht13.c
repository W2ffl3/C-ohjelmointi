#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    FILE *file;
    char filename[256];
    int num, count = 0;
    int min = INT_MAX, max = INT_MIN;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fscanf(file, "%d", &num) == 1) {
        count++;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }

    if (count > 0) {
        printf("Count of numbers: %d\n", count);
        printf("Lowest number: %d\n", min);
        printf("Highest number: %d\n", max);
    } else {
        printf("No numbers were found in the file.\n");
    }

    fclose(file);

    return 0;
}
