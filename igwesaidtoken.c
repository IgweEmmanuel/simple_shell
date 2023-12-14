#include "igwesaid.h"

/**
 * split_string - splits a string into words based on delimiters
 * @str: input string
 * @delim: delimiter string
 * Return: array of strings or NULL on failure
 */
char **split_string(char *str, char *delim)
{
    int q = 0, j = 0, k, m, num_words = 0;
    char **words;

    if (!str || str[0] == '\0')
        return NULL;

    delim = delim ? delim : " ";

    while (str[q])
    {
        if (!is_delimiter(str[q], delim) && (is_delimiter(str[q + 1], delim) || !str[q + 1]))
            num_words++;

        q++;
    }

    if (num_words == 0)
        return NULL;

    words = malloc((num_words + 1) * sizeof(char *));
    if (!words)
        return NULL;

    q = 0;
    j = 0;

    while (j < num_words)
    {
        while (is_delimiter(str[q], delim))
            q++;

        k = 0;
        while (!is_delimiter(str[q + k], delim) && str[q + k])
            k++;

        words[j] = malloc((k + 1) * sizeof(char));
        if (!words[j])
        {
            while (j--)
                free(words[j]);

            free(words);
            return NULL;
        }

        m = 0;
        while (m < k)
            words[j][m++] = str[q++];

        words[j][m] = '\0';
        j++;
    }

    words[j] = NULL;
    return words;
}
