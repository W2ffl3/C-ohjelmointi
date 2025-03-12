#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

char random_printable_char() {
    return (char)(33 + rand() % 94);
}

bool generate_password(char *password, int size, const char *word) {
    int word_len = strlen(word);
    int password_len = 2 * word_len + 1;

    if (password_len > size) {
        return false;
    }

    int password_index = 0;
    for (password_index = 0; password_index < password_len; password_index++) {
        if (password_index % 2 == 0) {
            password[password_index] = random_printable_char();
        } else {
            password[password_index] = word[(password_index / 2) % strlen(word)];
        }
    }

    password[password_len] = '\0';
    return true;
}

int main() {

    srand(time(NULL));
    char word[32];
    char password[128];
    bool success;

    while (1) {
        printf("Enter a word to generate a password (or 'stop' to quit): ");

        if (fgets(word, sizeof(word), stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        word[strcspn(word, "\n")] = '\0';

        if (strlen(word) >= sizeof(word) - 1) {
            fprintf(stderr, "Error: Input too long. Please enter a word shorter than 32 characters.\n");

            while (getchar() != '\n');

            continue;
        }

        if (strcmp(word, "stop") == 0) {
            break;
        }

        success = generate_password(password, sizeof(password), word);

        if (success) {
            printf("Generated password: %s\n", password);
        } else {
            printf("Error: Password cannot be generated, the word is too long!\n");
        }
    }

    return 0;
}
