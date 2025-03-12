#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) {
        return 0;
    }

    char target = repl[0];
    char replacement = repl[1];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            str[i] = replacement;
            count++;
        }
    }

    return count;
}

int main() {

    char text[100];
    char repl[3];

    printf("Enter the string: ");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")] = '\0';

    printf("Enter the replacement string: ");
    fgets(repl,sizeof(repl),stdin);
    repl[strcspn(repl,"\n")] = '\0';

    int count = replace_char(text, repl);

    if (count > 0) {
        printf("Modified string: %s\n", text);
        printf("Number of replacements: %d\n", count);
    }else {
        printf("String was not modified\n");
    }

    return 0;
}