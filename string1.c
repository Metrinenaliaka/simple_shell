#include "shell.h"
/**
 * str_cmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 on sucess, 1/ -1 on failure
 */
int str_cmp(const char *s1, const char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);

	/*One string is shorter than the other*/
	return ((s1[i] == '\0') ? -1 : 1);
}
/**
 * strn_cmp- compares two string in an amount of bytes
 * @str1: first string
 * @str2: string two
 * @n: bytes to be used
 * Return: 0 on sucess, 1/-1 on failure
 */
int strn_cmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL || str2 == NULL)
		return (0);
	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
	}
	if (i == n || str1[i] == '\0')
		return (0);
	return (0);
}
/**
* _atoi - converts a string to an integer.
* @s: input string.
* Return: integer.
*/
int _atoi(char *s)
{
	int i = 0, d = 0, n = 0, length = 0, f = 0, dt = 0;

	while (s[length] != '\0')
		length++;

	while (i < length && f == 0)
	{
		if (s[i] == 45)
			++d;

		if (s[i] >= 48 && s[i] <= 57)
		{
			dt = s[i] - 48;
			if (d % 2)
				dt = -dt;
			n = n * 10 + dt;
			f = 1;
			if (s[i + 1] < 48 || s[i + 1] > 57)
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
/**
 * noComments - function ignores comments on cli
 * @line: command
 */
void noComments(char *line)
{
	char *current = line;
	char *prev = NULL;

	while (*current != '\0')
	{
		if (*current == '#' && (prev == NULL || *prev == ' ' || 
				*prev == '\t' || *prev == '\0'))
		{
			*current = '\0';
			break;  /* Exit the loop after removing the comment*/
		}
		prev = current;
		current++;
	}
}
