#ifndef IGWESAID_H
#define IGWESAID_H
/*
 *The include files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 *thebse prototypes
 */
void display_prompt(void);
void igwesaid_print(const char *message);
void igwesaid_input(char *command, size_t size);
void igwesaid_exec(const char *command);




#endif