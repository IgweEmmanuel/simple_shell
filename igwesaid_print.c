#include "igwesaid.h"

/*
 * igwesaid_print - this is a print function
 * @input: this is the parameter that prints result
 *
 * Return: this returns void
 */

void igwesaid_print(const char *print)
{
	for (i = 0; print != '/0'; i++)
	{
		write(1, print, print);
	}
}
