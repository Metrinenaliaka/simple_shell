#include "shell.h"
/**
*_strlen - print the length of str
*@str: the string to be printed
*
*Return: the length of str
*/
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
/**
*_strcpy - copies a str to another
*@dest: the string to copy to
*@src: the str to be copied to dest
*
* Return: the final string
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
}
/**
 *_strcat - concatenates two strings
 *@dest: finale string
 *@src: string to be appended
 *Return: finale string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
		for (j = 0; src[j] != '\0'; j++)
		{
			dest[i] = dest[j];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
#include "main.h"
#include <stdio.h>
/**
*_strstr - locate substring
*@haystack:  str to search in
*@needle: sbustring
*
*Return: pointer to substring or NULL
*/
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (haystack[i + j] != needle[j])
				j++;
			break;
		}
		if (!needle[j])
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
*_strdup - return a pointer to  dup of a str
*@str: the string to be dup
*
*Return: the dup str or NULL
*/
char *_strdup(char *str)
{
	int len, i;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlen(str) + 1;
	s = (char *)malloc(len * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		s[i] = str[i];
	}
	return (s);
}
