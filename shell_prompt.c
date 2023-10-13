#include "shell.h"

/**
 * start_shell - Starts the shell's main loop
 *
 * Description: Initializes the shell, handles user input,
 * tokenizes commands, and executes them.
 */
void start_shell(char **argv)
{
	char *line = NULL, **commands, *envp[] = {NULL};
	size_t line_size = 0;
	ssize_t nread;
	int status = 0, count = 0;

	while (1)
	{
		nread = read_command(&line, &line_size);
		if (nread == -1)
			handle_getline_error(line);
		count++;
		commands = tokenize_string(line, " \n\t");
		if (commands[0])
		{
			if (!_strcmp(commands[0], "exit"))
			{
				if (commands[1])
				{
					int custom_status = _atoi(commands[1]);

					handle_custom_exit(custom_status, commands, line, &status);
				}
				else
				{
					free(line);
					free_array(commands);
					exit(status);
				}
			}
			else if (!_strcmp(commands[0], "env"))
			{
				print_environment_variables();
				status = 0;
			}
			else
				execute_shell_command(commands, envp, &status, argv, count);
		}
		free_array(commands);
		free(line);
		line = NULL;
	}
}

/**
 * read_command - Reads a line of command from the user
 * @line: The line buffer to store the command
 * @line_size: The size of the line buffer
 *
 * Return: Returns the number of characters read.
 */
ssize_t read_command(char **line, size_t *line_size)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(line, line_size, stdin));
}

/**
 * write_error - Writes an error message to STDERR
 *
 * @command: command
 * Description: Writes an error message
 */
void write_error(char *name, char *command, int index)
{
	char i[10] = {'\0'};

	int_to_string(index,i);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * write_exit_error - Writes an error message to STDERR
 *
 * @number: number
 * Description: Writes an error message
 */
void write_exit_error(char *number)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, "\n", 1);
}
