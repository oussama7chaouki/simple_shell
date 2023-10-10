#include "main.h"
/**
 * _atoi - Converts a string to an integer
 * @s:string
 * Return: 0 if no number or the number if exist
 */
int _atoi(char *s)
{
	int i = 0, neg = 0, exist = 0;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0';)
	{
		if (s[i] == '-')
			neg++;
		while (s[i] >= 48 && s[i] <= 57)
		{
			exist = 1;
			num = (num * 10) + (s[i] - '0');
			i++;
		}
		if (exist)
			break;
		i++;
	}
	if (neg % 2 != 0)
		return (-num);
	return (num);
}
