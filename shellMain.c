#include "shellMain.h"

/**
 * main - It checks the input and then calls either interactive
 * function or non interactive
 *
 * @ac: the number of arguments
 * @argv: array of strings
 *
 * Return: 0 if success
*/

int main(int ac __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *prompt = "#cisfun$ ";

	if (isatty(STDIN_FILENO))
	{
		_interactive(prompt);
	}
	else
	{
		non_interactive();
	}

	return (0);
}
