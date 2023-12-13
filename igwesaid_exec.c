#include "igwesaid.h"

/*
 * igwesaid_exec - This function executes the command
 * @input: this takes on an input from the user
 *
 * Return: this returns void
 */

void igwesaid_exec(const char *input)
{
	pid_t sub_process = fork();

	if (sub_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (sub_process == 0)
	{
		execve(input, input, NULL);
		perror("execve");
		exit(EXIT_FAILURE);

	}
	else
	{
		wait (NULL);	
	}
}
