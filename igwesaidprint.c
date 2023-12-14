#include "igwesaid.h"

void igwesaid_print(const char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}
