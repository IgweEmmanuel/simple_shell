#include "igwesaid.h"

/**
 * _erratoi - Integer conversion.
 * @s: The string to be converted.
 *
 * Return: The converted number if successful, -1 on error.
 */
int _erratoi(char *s)
{
    int k = 0;
    unsigned long int result = 0;

    if (*s == '+')
        s++;  /* Skip leading plus sign */

    while (s[k] != '\0')
    {
        if (s[k] >= '0' && s[k] <= '9')
        {
            result *= 10;
            result += (s[k] - '0');
            if (result > INT_MAX)
                return -1;  /* Overflow check */
        }
        else
            return -1;  /* Non-numeric character found */

        k++;
    }

    return result;
}

/**
 * print_error - Error messae.
 * @info: The parameter and return info struct.
 * @estr: String containing the specified error type.
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

/**
 * print_d - Prints a decimal (integer) number (base 10).
 * @input: The input number.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters printed.
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int count = 0;
    unsigned int _abs_, current;
    int k = 1000000000;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar;

    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;

    current = _abs_;
    while (k > 1)
    {
        if (_abs_ / k)
        {
            __putchar('0' + current / k);
            count++;
        }
        current %= k;
        k /= 10;
    }
    __putchar('0' + current);
    count++;

    return count;
}

/**
 * convert_number - A clone of atoi.
 * @num: Number to convert.
 * @base: Base for conversion.
 * @flags: Argument flags.
 *
 * Return: The converted string.
 */
char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }

    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;

    return ptr;
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 */
void remove_comments(char *buf)
{
    int k = 0;

    while (buf[k] != '\0')
    {
        if (buf[k] == '#' && (!k || buf[k - 1] == ' '))
        {
            buf[k] = '\0';
            break;
        }
        k++;
    }
}
