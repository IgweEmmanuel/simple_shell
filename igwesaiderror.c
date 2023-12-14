#include "igwesaid.h"

/**
 * _eputs - Prints to stderr.
 * @str: String to print.
 *
 * Return: returns void.
 */
void _eputs(char *str)
{
    int index;

    if (!str)
        return;

    for (index = 0; str[index] != '\0'; index++)
    {
        _eputchar(str[index]);
    }
}

/**
 * _eputchar - Writes the character c to stderr.
 * @c: The character to print.
 *
 * Return: On success 1. On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
    static int index;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
    {
        write(2, buffer, index);
        index = 0;
    }

    if (c != BUF_FLUSH)
        buffer[index++] = c;

    return 1;
}

/**
 * _putfd - Writes the character c to a given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success 1. On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
    static int index;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
    {
        write(fd, buffer, index);
        index = 0;
    }

    if (c != BUF_FLUSH)
        buffer[index++] = c;

    return 1;
}

/**
 * _putsfd - Prints an input string to a specified file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters put.
 */
int _putsfd(char *str, int fd)
{
    int count = 0;

    if (!str)
        return 0;

    while (*str)
    {
        count += _putfd(*str++, fd);
    }

    return count;
}
