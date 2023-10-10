#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * @str: the source string
 * Return: returns a pointer to the copy string.
 */
char *_strdup(char *str)
{
	char *duplic;
	int i, length;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
	{
	}

	duplic = (char *)malloc((sizeof(char) * length) + 1);
	if (duplic == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		duplic[i] = str[i];
	duplic[length] = '\0';

	return (duplic);
}
