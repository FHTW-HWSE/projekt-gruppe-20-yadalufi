#include <stdio.h>
#include "menu.h"
#include "file.h"

void display_menu() {
    printf("=== MENU ===\n");
    printf("1. Create plan \n");
    printf("2. Show seats \n");
    printf("3. Add student \n");
    printf("4. Edit student \n");
    printf("5. Remove student \n");
    printf("6. Quit \n");
    printf("============\n");
    return;
}

int menu_choice(){
    int choice = 0;

    while (choice != 6) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
// insert function here
                break;
            case 2:
// insert function here
                break;
            case 3:
// insert function here
                break;
            case 4:
// insert function here
                break;
            case 5:
// insert function here
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return choice;
}