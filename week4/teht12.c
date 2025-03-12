#include <stdio.h>
#include <string.h>

int count_words(const char* str, const char *word) {

    int count = 0;
    const char *ptr = str;

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr++;
    }

    return count;
}

int main() {

    char str[1000], word[100];
    int count;

    while (1) {
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        printf("Enter a word: ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "stop") == 0) {
            printf("Stopping code");
            break;
        }

        count = count_words(str, word);

        printf("The word \"%s\" appears %d times in the string.\n", word, count);
    }

    return 0;
}
