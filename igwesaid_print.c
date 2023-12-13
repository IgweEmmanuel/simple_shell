#include "igwesaid.h"

/*
 * igwesaid_print - this is a print function
 * @input: this is the parameter that prints result
 *
 * Return: this returns void
 */

void igwesaid_print(const char *input)
{
	write(STDOUT_FILENO, input, lenofstring(input));
}
