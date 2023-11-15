#include "shell.h"

/**
 * finding_location - function finds the location of a command It returns
 * a pointer to a string that represents the full path
 * @command: command
 *
 * Return: A pointer to a string that represents the full path of the
 * command
*/

char *finding_location(char *command)
{
	char *path, *cpy_path, *path_tok, *file_path;
	int command_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		cpy_path = strdup(path);
		command_len = strlen(command);
		path_tok = strtok(cpy_path, ":");

		while (path_tok != NULL)
		{
			dir_len = strlen(path_tok);
			file_path = malloc(command_len + dir_len + 2);
			strcpy(file_path, path_tok);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(cpy_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(cpy_path);
		if (stat(command, &buffer) == 0)
		{
		return (command);
		}
		return (NULL);
	}
	return (NULL);
}
