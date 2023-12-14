#include "igwehead.h"

void igwesaid_input(char *command, size_t size) {
    if (fgets(command, size, stdin) == NULL) {
        if (feof(stdin)) {
            igwesaid_print("\n");
            exit(EXIT_SUCCESS);
        } else {
            igwesaid_print("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\n")] = '\0'; // Remove newline
}