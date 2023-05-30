#include <stdio.h>
#include "menu.h"
#include "file.h"

enum menu_elements {
    create_plan = 1,
    show_rm,
    show_seats,
    add_student,
    edit_student,
    remove_student,
    load_csv_file,
    contact_tracing,
    quit} choice;

void display_menu() {
    printf("=== MENU ===\n");
    printf("1. Create plan\n");
    printf("2. Show room\n");
    printf("3. Show seats\n");
    printf("4. Add student\n");
    printf("5. Edit student\n");
    printf("6. Remove student\n");
    printf("7. Load CSV file\n");
    printf("8. Contact tracing\n");
    printf("9. Quit\n");
    printf("============\n");
    return;
}

int menu_choice(){
    int choice = 0;
    room *Room = NULL;                      // hier mit fp: wenn kein File da, dann room/student neu, sonst aus File laden
    student *Student = NULL;


    while (choice != quit) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case create_plan:
                Room = create_room();
                break;
            case show_rm:
                if (Room == NULL) {
                    printf("No room to show\n");
                } else {
                show_room(Room, Student);
                }
                break;
            case show_seats:
// insert function here
                break;
            case add_student:
                Student = create_student(Student);
                break;
            case edit_student:
// insert function here
                break;
            case remove_student:
// insert function here
                break;
            case load_csv_file:
// insert function here
                break;
            case contact_tracing:
// insert function here
                break;
            case quit:
                printf("Goodbye!\n");
                int error;
                error = free_student(Student);
                if (error != 0)
                {
                    fprintf(stderr, "free_student failed");
                }

                error = free_room(Room);
                if (error != 0)
                {
                    fprintf(stderr, "free_room failed\n");
                }
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return choice;
}
