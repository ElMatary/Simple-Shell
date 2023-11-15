#include "shellMain.h"

/**
 * env - enviroments.
 * Return: no thing.
*/

void env(void)
{
	int i = 0;
	char buffer[256];
	int len;

	while (environ[i])
	{
	len = snprintf(buffer, sizeof(buffer), "%s\n", environ[i]);
	write(STDOUT_FILENO, buffer, len);
	i++;
	}
}
