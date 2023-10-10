#include "main.h"
/**
 * _strcmp - compare string
 * @s1:first string
 * @s2:second string
 * Return: differnce between the first non-matching character.
 */
int _strcmp(char *s1, char *s2)
{
	int j, k, i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			k = s1[i];
			j = s2[i];
			return (k - j);
		}
		i++;
	}
	if (s1[i] != '\0')
	{
		k = s1[i];
		return (k);
	}
	else
	{
		j = s2[i];
		return (-j);
	}
}
