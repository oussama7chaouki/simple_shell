#include "shell.h"

/**
 * handle_exit_status - Handles the exit status for a command.
 * @custom_status: The status to check.
 * @cmd_args: The command arguments.
 * @token: A pointer to dynamically allocated memory.
 * @exit_status: A pointer to an int to hold the exit status value.
 *
 * Return: void.
 */
void handle_exit_status(int custom_status, char **cmd_args, char **token,
		int *exit_status)
{
	if (custom_status == -1 ||
		(custom_status == 0 && cmd_args[1][0] != '0') ||
		custom_status < 0)
	{
		write_exit_error(cmd_args[1]);
		*exit_status = 2;
	}
	else
	{
		free(*token);
		free_array(cmd_args);
		exit(custom_status);
	}
}

/**
 * handle_custom_exit - Handles custom exit statuses for a command.
 * @custom_status: The exit status to check.
 * @cmd_args: The array containing the command and its arguments.
 * @input_line: A pointer to the input line.
 * @exit_status: A pointer to an int to hold the return exit status value.
 *
 * Return: void.
 */
void handle_custom_exit(int custom_status, char **cmd_args,
		char *input_line, int *exit_status)
{
	if (custom_status == -1 ||
		(custom_status == 0 && cmd_args[1][0] != '0') ||
		custom_status < 0)
	{
		write_exit_error(cmd_args[1]);
		*exit_status = 2;
	}
	else
	{
		free(input_line);
		free_array(cmd_args);
		exit(custom_status);
	}
}

