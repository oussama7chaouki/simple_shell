#include "shell.h"
/**
 * free_array - Frees memory allocated for an array of strings.
 * @array: A pointer to the dynamically allocated array of strings.
 *
 * This function frees the memory allocated for an array of strings.
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
