#include "shell.h"

/**
 * execute_shell_command - Execute a shell command
 * and its arguments by searching in PATH
 * @cmd_args: The command and its arguments as an array of strings
 * @env_vars: The environment variables
 * @exit_status: The pointer to an int where the exit status will be stored
 */
void execute_shell_command(char **cmd_args, char **env_vars, int *exit_status, char **argv, int index)
{
	char *cmd_path = NULL;
	int child_pid;

	if (access(cmd_args[0], X_OK) == 0)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(cmd_args[0], cmd_args, env_vars);
		}
		else
		{
			wait_child_process(exit_status);
		}
	}
	else if (find_command_path(cmd_args[0], &cmd_path))
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(cmd_path, cmd_args, env_vars);
		}
		else
		{
			wait_child_process(exit_status);
		}

		free(cmd_path);
	}
	else
	{
		*exit_status = 127;
		write_error(argv[0], cmd_args[0], index);
	}
}

/**
 * find_command_path - Searches for the full path of a command
 * in the PATH environment variable
 * @command: The command to search for
 * @cmd_path: Pointer to store the full path of the command
 *
 * Return: 1 if found, 0 if not found
 */
int find_command_path(char *command, char **cmd_path)
{
	char *token, *path_env;
	int found = 0;

	path_env = get_environment_variable("PATH");

	if (path_env != NULL)
	{
		char *path_env_copy = strdup(path_env);

		token = strtok(path_env_copy, ":");

		while (token != NULL && !found)
		{
			*cmd_path = malloc(strlen(token) + strlen(command) + 2);
			if (*cmd_path != NULL)
			{
				strcpy(*cmd_path, token);
				strcat(*cmd_path, "/");
				strcat(*cmd_path, command);

				if (access(*cmd_path, X_OK) == 0)
				{
					found = 1;
				}

				if (!found)
				{
					free(*cmd_path);
				}
			}

			token = strtok(NULL, ":");
		}

		free(path_env_copy);
	}

	return (found);
}

/**
 * wait_child_process - Waits for a child process to end
 * and gets its exit status
 * @exit_status: Pointer to the exit status variable to store the exit status
 *
 * Return: void
 */
void wait_child_process(int *exit_status)
{
	int child_status;

	if (wait(&child_status) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(child_status))
	{
		*exit_status = WEXITSTATUS(child_status);
	}
}

/**
 * get_environment_variable - Searches for an environment
 * variable and returns its value
 * @var_name: The name of the environment variable to search for
 *
 * Return: Pointer to the value of the environment variable,
 * or NULL if not found
 */
char *get_environment_variable(const char *var_name)
{
	int i;
	int name_length = _strlen((char *)var_name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(var_name, environ[i], name_length))
		{
			if (environ[i][name_length] == '=')
			{
				return (environ[i] + name_length + 1);
			}
		}
	}

	return (NULL);
}

/**
 * print_environment_variables - Prints the environment variables to stdout
 *
 * Return: void
 */
void print_environment_variables(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

