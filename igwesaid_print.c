#include "igwesaid.h"

/**
 * igwesaid_print - a function that prints to STDOUT
 * @input: the input of the user
 * Return: void
*/

void igwesaid_print(const char *input)
{
	write(STDOUT_FILENO, input, lenofstring(input));
}
