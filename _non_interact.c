#include "shellMain.h"

/**
 * non_interactive - read command and proccess it untile error or exit
 * it is non-interactive interface
 *
 * Return: void
*/

void non_interactive(void)
{
	char *lptr = NULL;
	size_t n = 0;
	ssize_t n_read;

	while ((n_read = getline(&lptr, &n, stdin)) != -1)
	{
		process_non_inter(lptr);
	}

	free(lptr);
}
