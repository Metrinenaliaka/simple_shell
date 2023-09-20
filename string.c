#include "shell.h"
/**
 * str_len - finds the length of a string
 * @s: string whose length is calculated
 * Return: len;
 */
int str_len(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/**
 * str_cpy - copies one string to another
 * @dest: where to copy
 * @src: where to copy from
 * Return: dest
 */
char *str_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * str_cat- concatinating two strings
 * @dest: string that receives the other
 * @src: string to connect to the other
 * Return: dest
 */
char *str_cat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * str_dup - duplicates strings
 * @str: string to be duplicated
 * Return: new string
 */
char *str_dup(char *str)
{
	int size, i = 0;
	char *str1;

	if (str == NULL)
	{
		return (NULL);
	}
	size = str_len(str) + 1;
	str1 = (char *)malloc(size * sizeof(char));
	if (str1 == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		*(str1 + i) = *(str + i);
		i++;
	}
	return (str1);
}
/**
 * _strstr - finds the first occurence of a substring
 * @haystack: string to be checked
 * @needle: substring to be found
 * Return: needle or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0;

	for (; haystack[i] != '\0'; haystack++)
	{
		while (haystack[i] == needle[j] && needle[j] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
		{
			return (haystack);
		}
	}
	return (NULL);
}
