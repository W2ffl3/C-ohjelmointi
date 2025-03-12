#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

int is_integer(const char *str) {
    if (*str == '-') {
        str++;
    }

    if (*str == '\0') {
        return 0;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}

int main() {
    nnode *head = NULL, *temp = NULL, *new_node = NULL;
    char input[100];
    int number;

    while (1) {

        printf("Enter a number (or 'end' to stop): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "end") == 0) {
            break;
        }

        if (is_integer(input)) {
            number = atoi(input);

            new_node = (nnode *)malloc(sizeof(nnode));
            if (new_node == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                return 1;
            }

            new_node->number = number;
            new_node->next = NULL;

            if (head == NULL) {
                head = new_node;
            } else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        } else {
            printf("Error: Invalid input, please enter a number or 'end' to stop.\n");
        }
    }

    printf("\nEntered numbers:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->number);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        nnode *to_free = temp;
        temp = temp->next;
        free(to_free);
    }

    return 0;
}
