#include "igwesaid.h"

/**
 * main - entry point
 * Return: Always 0 if successful
*/

int main(void)
{
	char igwesaid_cmd[215];
	int i;

	for (i = 0; i >= 0; i++)
	{
		igwesaid_prompt();
		igwesaid_input(igwesaid_cmd, sizeof(igwesaid_cmd));
		igwesaid_exec(igwesaid_cmd);
	}
	return (0);
}
