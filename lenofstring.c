#include "igwesaid.h"

/**
 * lenofstring - counts the length of a string
 * @text: the string to be counted
 * Return: an integer
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
