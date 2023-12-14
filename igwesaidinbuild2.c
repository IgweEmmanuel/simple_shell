#include "igwesaid.h"

/**
 * display_history - Displays the history list, one command per line,
 *                   preceded with line numbers starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int display_history(info_t *info)
{
    print_list(info->history);
    return 0;
}

/**
 * remove_alias - Deletes alias.
 * @info: Parameter struct.
 * @alias_str: The string representing the alias.
 * Return: 0 on success, 1 on error.
 */
int remove_alias(info_t *info, char *alias_str)
{
    char *equals_position, c;
    int result;

    equals_position = _strchr(alias_str, '=');
    if (!equals_position)
        return 1;

    c = *equals_position;
    *equals_position = 0;

    result = delete_node_at_index(&(info->alias),
                                  get_node_index(info->alias, node_starts_with(info->alias, alias_str, -1)));

    *equals_position = c;

    return result;
}

/**
 * set_alias - Sets an alias.
 * @info: Parameter struct.
 * @alias_str: The string representing the alias.
 * Return: 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *alias_str)
{
    char *equals_position;

    equals_position = _strchr(alias_str, '=');
    if (!equals_position)
        return 1;

    if (!*++equals_position)
        return remove_alias(info, alias_str);

    remove_alias(info, alias_str);

    return (add_node_end(&(info->alias), alias_str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node.
 * Return: 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
    char *equals_position = NULL, *alias_start = NULL;

    if (node)
    {
        equals_position = _strchr(node->str, '=');

        while (alias_start <= equals_position)
            _putchar(*alias_start++);

        _putchar('\'');
        _puts(equals_position + 1);
        _puts("'\n");

        return 0;
    }

    return 1;
}

/**
 * manage_alias - Mimics the alias built-in (man alias).
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int manage_alias(info_t *info)
{
    int i;
    char *equals_position = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return 0;
    }

    i = 1;
    while (info->argv[i])
    {
        equals_position = _strchr(info->argv[i], '=');

        if (equals_position)
            set_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));

        i++;
    }

    return 0;
}
