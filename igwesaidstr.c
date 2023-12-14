#include "igwesaid.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: Integer length of the string.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s && s[i]; i++)
		;

	return i;
}

/**
 * _strcmp - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2 && *s1 == *s2; s1++, s2++)
		;

	return (*s1 - *s2);
}

/**
 * starts_with - Checks if pin starts with haystack.
 * @stick: The string to search.
 * @pin: The substring to find.
 *
 * Return: Address of the next character of haystack or NULL.
 */
char *starts_with(const char *stick, const char *pin)
{
	for (; *pin && *pin == *stick; pin++, stick++)
		;

	return *pin ? NULL : (char *)stick;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	for (; *dest; dest++)
		;

	for (; (*dest++ = *src++); )
		;

	return ret;
}
