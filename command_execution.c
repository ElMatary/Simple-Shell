#include "shellMain.h"

/**
 * exec_cmd - execution commands shell
 * @argv: arguments vector (array of strings)
 * Return: no thing
*/

void exec_cmd(char **argv)
{

	pid_t pid;
	int status;

	if (argv)
	{
		char *command = argv[0];
		char *command_r = finding_location(command);

		pid = fork();
		if (pid == 0)
		{
			if (execve(command_r, argv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("Error:");
			return;
		}
		else
		{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}

}
