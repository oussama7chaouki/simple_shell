#include "shell.h"

/**
 * int_to_string - converts a number to a string.
 * @number: number to be converten in an string.
 * @string: the return string
 * Return: the number as string.
 */
void int_to_string(int number, char *string)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % 10)];
		else
			string[index++] = letters[cociente % 10];
		cociente /= 10;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}
/**
 * str_reverse - reverses a string.
 *
 * @string: pointer to string.
 * Return: void.
 */
void str_reverse(char *string)
{

	int i = 0, length = _strlen(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
