#include "shell.h"

/**
 * _interactive - read command and proccess it untile error or exit
 *
 * @prompt : display
 *
*/

void _interactive(char *prompt)
{
	char *lptr = NULL;
	size_t n = 0;
	ssize_t n_read;
	char *exiting_shell = "Exiting shell....\n";

	while (1)
	{
		char buffer[256];
		int len;

		len = snprintf(buffer, sizeof(buffer), "%s", prompt);
		write(STDOUT_FILENO, buffer, len);
		n_read = getline(&lptr, &n, stdin);
		if (n_read == -1)
		{
			write(STDOUT_FILENO, exiting_shell, strlen(exiting_shell));
			free(lptr);
			return;
		}

		user_process(lptr);
	}

	free(lptr);
}
