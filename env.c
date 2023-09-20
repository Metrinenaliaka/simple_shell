#include "shell.h"
/**
  * get_env - gets the environment variables to execute
  *@name: environment variable
  *Return: env or null
  */
char *get_env(char *name)
{
	size_t name_len;
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);
	name_len = str_len(name);
	for (env = environ; *env != NULL; env++)
	{
		if (strn_cmp(*env, name, name_len) == 0
				&& (*env)[name_len] == '=')
			return (&(*env)[name_len + 1]);
	}
	return (NULL);
}
/**
 * printEnv - Prints env to stdout
 */
void printEnv(void)
{
/*	char **env = environ;*/
	long int len;
	int i = 0;

	while (environ[i])
	{
		len = str_len(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
