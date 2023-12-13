#include "igwesaid.h"

/**
 * igwesaid_exec - a function that executes the command
 * @input: the input from the user
 * Return: void 
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
		wait(NULL);	
	}
}
