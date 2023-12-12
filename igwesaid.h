#ifndef IGWESAID_H
#define IGWESAID_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void igwesaid_prompt(void);
void igwesaid_print(const char *input);
void igwesaid_exec(const char *input);
void igwesaid_cmd_do(char *input, size_t size);
int lenofstring(const char *text);

#endif
