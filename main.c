#include <stdio.h>
#include "process.h"
#include "memory.h"
#include "filesystem.h"

int main() {

    init_memory();

    int choice;
    char filename[32];
    int size, pid;

    while (1) {
        printf("\n--- MiniKernel ---\n");
        printf("1. Create Process\n");
        printf("2. Schedule Process\n");
        printf("3. Terminate Process\n");
        printf("4. List Processes\n");
        printf("5. Allocate Memory Page\n");
        printf("6. Show Memory\n");
        printf("7. Create File\n");
        printf("8. List Files\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_process();
                break;

            case 2:
                scheduler();
                break;

            case 3:
                printf("Enter PID: ");
                scanf("%d", &pid);
                terminate_process(pid);
                break;

            case 4:
                list_processes();
                break;

            case 5:
                printf("Enter PID: ");
                scanf("%d", &pid);
                allocate_page(pid);
                break;

            case 6:
                show_memory();
                break;

            case 7:
                printf("Filename: ");
                scanf("%s", filename);
                printf("Size: ");
                scanf("%d", &size);
                create_file(filename, size);
                break;

            case 8:
                list_files();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}