#include <stdio.h>
#include <string.h>

int main() {

    char str[100];

    while (1) {
        printf("Enter a string: ");

        if (fgets(str, sizeof(str), stdin)) {
            str[strcspn(str, "\n")] = '\0';
        }

        printf("Length of string = %zu\n", strlen(str));

        if (strcmp(str,"stop") == 0) {
            printf("You entered a stop.\n");
            break;
        }
    }

    return 0;
}