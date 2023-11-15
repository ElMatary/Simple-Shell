#include "shellMain.h"

/**
 * process_non_inter - if shell in non interactive mode take user input.
 * @user_input: user input.
 * Return: no thing
*/
void process_non_inter(char *user_input)
{
	const char *delim = " \n";
	int num_tokens = 0, i;
	char *token, *cpy_lptr;
	char **argv;

	if (strcmp(user_input, "exit\n") == 0)
	{
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(user_input, "env\n") == 0)
	{
		env();
		return;
	}
	cpy_lptr = strdup(user_input);

	token = strtok(user_input, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(cpy_lptr, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	exec_cmd(argv);
	for (i = 0; i < num_tokens; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(cpy_lptr);
}
