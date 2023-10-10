#ifndef SHELL_H
#define SHELL_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include<string.h>
#include<sys/wait.h>
#include <limits.h>

extern char **environ;

void execute_shell_command(char **cmd_args, char **env_vars, int *exit_status);
int find_command_path(char *command, char **cmd_path);
void wait_child_process(int *exit_status);
char *get_environment_variable(const char *var_name);
void print_environment_variables(void);
void handle_getline_error(char *input_line);
void handle_exit_status(int custom_status, char **cmd_args, char **token,
	int *exit_status);
void handle_custom_exit(int custom_status, char **cmd_args,
	char *input_line, int *exit_status);
void start_shell(void);
ssize_t read_command(char **line, size_t *line_size);
void write_error(char *command);
void write_exit_error(char *number);
char **tokenize_string(char *str, char *delimiters);
int main(void);
void non_interactive_mode(char *token, int *status);
void free_array(char **array);
char *_strdup(const char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

#endif
