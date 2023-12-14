#include "igwesaid.h"

/**
 * _myenv - Prints the current environment.
 * @info: Structure containing potential arguments.
 *
 * Returns: Always 0
 */
int _myenv(info_t *info) {
    print_list_str(info->env);
    return 0;
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: Environment variable name.
 *
 * Returns: The value of the environment variable.
 */
char *_getenv(info_t *info, const char *name) {
    /* Traverse the environment linked list to find the specified variable.*/
    list_t *node = info->env;
    char *p;

    while (node) {
        p = starts_with(node->str, name);
        if (p && *p)
            return p;
        node = node->next;
    }
    return NULL;
}

/**
 * _mysetenv - Initializes a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments.
 *
 * Returns: Always 0
 */
int _mysetenv(info_t *info) {
    int k = 1;

    /* Check if the correct number of arguments is provided.*/
    if (info->argc != 3) {
        _eputs("Incorrect number of arguments\n");
        return 1;
    }

    while (k <= info->argc) {
        if (_setenv(info, info->argv[k], info->argv[k + 1]))
            return 0;
        k += 2;
    }

    return 1;
}

/**
 * _myunsetenv - Removes an environment variable.
 * @info: Structure containing potential arguments.
 *
 * Returns: Always 0
 */
int _myunsetenv(info_t *info) {
    int k = 1;

    /* Check if the minimum number of arguments is provided.*/
    if (info->argc == 1) {
        _eputs("Too few arguments.\n");
        return 1;
    }

    /* Loop through the arguments to unset environment variables.*/
    while (k < info->argc) {
        _unsetenv(info, info->argv[k]);
        k++;
    }

    return 0;
}

/**
 * populate_env_list - Populates the environment linked list.
 * @info: Structure containing potential arguments.
 *
 * Returns: Always 0
 */
int populate_env_list(info_t *info) {
    list_t *node = NULL;
    size_t k = 0;

    /* Populate the environment linked list with elements from the environ array.*/
    while (environ[k]) {
        add_node_end(&node, environ[k], 0);
        k++;
    }

    info->env = node;
    return 0;
}
