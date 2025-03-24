#include "minishell.h"

int ft_echo(char **args, char *arg) // n indicates if echo is called with or without arguments (strings)
{
	int i;

	i = 0;
	if (!args)
	{
		if (arg == NULL)
			printf("\n");
		return (1);
	}
	while(args[i])
	{
		printf("%s\n", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!arg)
		printf("\n");
	return (0);
}

int ft_cd(char *path)
{
	char *home;
	char *cwd;

	home = getenv("HOME");	//set home to enter home directory if cd is used without a path
	cwd = NULL;
	if(!path)
	{
		if(home && chdir(home) == -1)
		{
			perror("minishell: cd");
			return (1);
		}
	}
	else
	{
		if (chdir(path) == -1)	//enter directory if it exists
		{
			perror("minishell: cd");
			return (1);
		}
	}
	cwd = getcwd(NULL, 0); //get new directory as a string e.g. "home/user/username"
	if (cwd != NULL)
	{
		printf("%s", cwd);
		free(cwd);
	}
	else
	{
		perror("minishell: getcwd");
		return (1);
	}
	return (0);
}

void ft_exit(char *arg)
{
	int status;

	status = 0;
	if (arg == NULL)
		exit(status);
	if(is_number(arg))
	{
		status = ft_atoi(arg);
		exit(status);
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", arg);
		exit(255);
	}
}

int ft_pwd(void)
{
	char *cwd;

	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	else
	{
		perror("minishell: pwd");
		return (1);
	}
	return (0);
}
