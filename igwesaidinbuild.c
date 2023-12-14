#include "igwesaid.h"

/**
 * exit_shell - Exits the shell.
 * @info: Structure containing potential arguments.
 * Return: Exits with a given exit status (0) if info.argv[0] != "exit".
 */
int exit_shell(info_t *info)
{
    int exit_status;

    if (info->argv[1])  /* If there is an exit argument */
    {
        exit_status = _erratoi(info->argv[1]);
        if (exit_status == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return 1;
        }
        info->err_num = exit_status;
        return -2;
    }

    info->err_num = -1;
    return -2;
}

/**
 * change_directory - Changes the current directory of the process.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int change_directory(info_t *info)
{
    char *current_dir, *target_dir, buffer[1024];
    int chdir_result;

    current_dir = getcwd(buffer, 1024);

    if (!info->argv[1])
    {
        target_dir = _getenv(info, "HOME=");
        if (!target_dir)
            chdir_result = chdir((target_dir = _getenv(info, "PWD=")) ? target_dir : "/");
        else
            chdir_result = chdir(target_dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(current_dir);
            _putchar('\n');
            return 1;
        }

        _puts(_getenv(info, "OLDPWD="));
        _putchar('\n');
        chdir_result = chdir((target_dir = _getenv(info, "OLDPWD=")) ? target_dir : "/");
    }
    else
    {
        chdir_result = chdir(info->argv[1]);
    }

    if (chdir_result == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }

    return 0;
}

/**
 * display_help - Displays help information.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int display_help(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("help call works. Function not yet implemented \n");

    if (0)
        _puts(*arg_array); /* temp att_unused workaround */

    return 0;
}
