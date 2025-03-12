#include <stdio.h>

#define MAX_ITEMS 40
#define MAX_NAME_LENGTH 50

typedef struct menu_item_ {
    char name[MAX_NAME_LENGTH];
    double price;
} menu_item;

int main() {
    FILE *file;
    char filename[256];
    menu_item menu[MAX_ITEMS];
    int item_count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for reading\n", filename);
        return 1;
    }

    while (item_count < MAX_ITEMS && fscanf(file, "%49[^;]; %lf\n", menu[item_count].name, &menu[item_count].price) == 2) {
        item_count++;
    }

    fclose(file);

    printf("\n");
    printf("%-8s %-50s\n", "Price", "Item Name");
    printf("%-8s %-50s\n", "------", "----------");

    for (int menu_index = 0; menu_index < item_count; menu_index++) {
        printf("%8.2f %-50s\n", menu[menu_index].price, menu[menu_index].name);
    }

    return 0;
}
