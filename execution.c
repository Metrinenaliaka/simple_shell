#include "shell.h"
/**
 *executeCommand - executes command parsed from cli
 *@argv: array of strings
 *
 */
void executeCommand(char **argv)
{
	char *command;
	pid_t child;
	int status = 0;

	command = searchCommand(argv[0], argv);
	if (command == NULL)
		return;
	child = fork();
	if (child == -1)
	{
		perror("Child process creation failed");
		exit(2);
	}
	else if (child == 0)
	{
		execve(command, argv, NULL);
		free(command);
		perror("./hsh: ");
	}
	else
	{
		wait(&status);
	}
}
/**
 *parsing - tokenizes the commands from cli
 *@command: command passed from cli
 */
void parsing(char *command)
{
	char *token, *copy, **argv;
	char *delim = " \n";
	int i = 0, count = 0;

	noComments(command);
	copy = str_dup(command);
	if (copy == NULL)
		return;
	token = strtok(copy, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	count++;
	argv = malloc(sizeof(char *) * count);
	if (argv == NULL)
	{
		perror("Memory allocatio failed");
		free(argv);
		return;
	}
	token = strtok(command, delim);
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	executeCommand(argv);
	free(argv);
	free(copy);
}
