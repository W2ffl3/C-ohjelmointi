#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 80

int main() {
    FILE *file;
    char filename[256];
    char lines[MAX_LINES][MAX_LENGTH + 1];
    int line_count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for reading\n", filename);
        return 1;
    }

    while (line_count < MAX_LINES && fgets(lines[line_count], MAX_LENGTH + 1, file) != NULL) {
        line_count++;
    }

    fclose(file);

    for (int rivi = 0; rivi < line_count; rivi++) {
        for (int merkki = 0; lines[rivi][merkki] != '\0'; merkki++) {
            lines[rivi][merkki] = toupper((unsigned char)lines[rivi][merkki]);
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename);
        return 1;
    }

    for (int rivi = 0; rivi < line_count; rivi++) {
        fputs(lines[rivi], file);
    }

    fclose(file);

    printf("File processed successfully.\n");

    return 0;
}
