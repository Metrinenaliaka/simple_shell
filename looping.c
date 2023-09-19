#include "shell.h"
/**
 * shell_loop - creates an infinite loop on cli
 *
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t bytes = 0;
	ssize_t readChars;

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
			fflush(stdout);
		}
		readChars = getline(&line, &bytes, stdin);
		if (readChars == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (readChars > 0 && line[readChars - 1] == '\n')
		{
			line[readChars - 1] = '\0';
		}
		parsing(line);
		if (!(isatty(STDIN_FILENO)))
			break;
		free(line);
		line = NULL;
	}
	free(line);
}
/**
 *main - main function
 *@ac: argument count
 *@av: argument vector
 *Return: 0 0n sucess
 */
int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	shell_loop();
	return (0);
}
