#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define PROMPT "#cisfun$ "

void execute_command(char *cmd)
{
	pid_t pid = fork();
	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	{
	else if (pid == 0)
	char *argv[] = {cmd, NULL};
	execve(cmd, argv, NULL);
	perror("./shell");
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
	printf(PROMPT);
	if (getline(&line, &len, stdin) == -1)
	{
	if (feof(stdin))
	{
	free(line);
	exit(EXIT_SUCCESS);
	}
	else
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}
	}

	line[strcspn(line, "\n")] = 0; // Remove newline character
	if (strlen(line) > 0)
	{
	execute_command(line);
	}
	}

	free(line);
	return 0;
}
