#include "shell.h"
/**
 * findpath - finds executable file in PATH
 * @command: command passed from stdin
 * Return: filepath or NULL
 */
char *findpath(char *command)
{
	char *path, *filePath = NULL, *pathCopy, *token;
	int flag = 0, pathlen;
	struct stat buf;

	path = get_env("PATH");
	if (path == NULL)
		return (NULL);
	pathCopy = str_dup(path);
	token = strtok(pathCopy, ":");
	while (token)
	{
		pathlen = str_len(token) + str_len(command) + 2;
		filePath = malloc(pathlen);
		if (filePath == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}
		str_cpy(filePath, token);
		str_cat(filePath, "/");
		str_cat(filePath, command);
		if (stat(filePath, &buf) == 0)
		{
			flag = 1;
			break;
		}
		free(filePath);
		filePath = NULL;
		token = strtok(NULL, ":");
	}
	free(pathCopy);
	if (flag == 0)
	{
		perror("Command not found");
		return (NULL);
	}
	return (filePath);
}
/**
 *searchCommand - takes command from cli and searches it from builtin/path
 *@command: input from cli
 *@argv: vector of arguments
 *Return: pointer to command
 */
char *searchCommand(char *command, char **argv)
{
	struct stat buf;
	char *foundPath;
	int status = 0;

	command = argv[0];
	if (stat(command, &buf) == 0)
		return (command);
	if (str_cmp(command, "exit") == 0 && argv[1] != NULL)
	{
		status = _atoi(argv[1]);
		if (status < 0)
		{
			perror("Illegal Number");
			return (NULL);
		}
		exit(status);
	}
	else if (str_cmp(command, "exit") == 0 && argv[1] == NULL)
		exit(status);
	if (str_cmp(command, "env") == 0)
		printEnv();
	foundPath = findpath(command);
	return (foundPath);
}
