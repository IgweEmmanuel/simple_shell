#include "igwesaid.h"

/*
 * Author - Igwe and Oussaid
 * 
 *
 *
 */

/*
 * main - this prints the shell prompt
 *
 * Return: returns always success 
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
	return 0;
}
