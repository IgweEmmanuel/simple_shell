#include "igwesaid.h"
/*
 * main - displays the programme as entry point.
 *
 * Return: success
 */

int main(void) {
    char command[120];

    while (1) {
        display_prompt();
        igwesaid_input(command, sizeof(command));
        igwesaid_exec(command);
    }





    

    return 0;
}