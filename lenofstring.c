#include "igwesaid.h"

/*
 * lenofstring - this checks for the length of a string
 * @text: this parameter represents the string
 *
 * Return: this returns length 
 */

int lenofstring(const char *text)
{
 	int i;
	size_t len = 0;

	for (i = 0; text != '\0'; i++)
	{
		len++;
	}
	return len;
}
