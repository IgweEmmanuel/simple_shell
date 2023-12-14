#include "igwesaid.h"
/**
 * igwesaid_exec - executes the files
 * @command: this is the input file
 *
 * Return: void
 */
void igwesaid_exec(const char *command) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        igwesaid_print("Error forking process.\n");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {

        char *args[128];
        int arg_count = 0;

        char *token = strtok((char *)command, " ");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; 
    
        execvp(args[0], args);

        igwesaid_print("Error executing command.\n");
        exit(EXIT_FAILURE);
    } else {

        wait(NULL);
    }
}