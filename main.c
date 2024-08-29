#include "main.h"

int main(void)
{
	char *input;
	pid_t pid;
	int status;

	while (1)
	{
		display_prompt();
		input = read_input();

		if (input == NULL)
		{
			free(input);
			continue;
		}

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			free(input);
			continue;
		}

		if (pid == 0) /* Child process */
		{
			execute_command(input);
		}
		else /* Parent process */
		{
			wait(&status);
		}

		free(input);
	}

	return 0;
}
