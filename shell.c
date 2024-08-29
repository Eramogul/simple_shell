#include "main.h"

void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

char *read_input(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&buffer, &bufsize, stdin);

	if (nread == -1)
	{
		if (feof(stdin)) /* Handle Ctrl+D */
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			return NULL;
        }
	}

	buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline character */
	return buffer;
}

void execute_command(char *cmd)
{
	char *argv[2];
	argv[0] = cmd;
	argv[1] = NULL;

	if (execve(cmd, argv, NULL) == -1)
	{
		perror(cmd);
	}
	exit(EXIT_FAILURE); /* Terminate child process if execve fails */
}
