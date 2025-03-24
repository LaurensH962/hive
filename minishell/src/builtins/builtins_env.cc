#include "minishell.h"

// Adds enviroment variables to the environment array
int ft_export(char ***env, char **var, char **value)
{
	int i;
	char *new_value;
	int env_size;
	char **new_env;
	int j;

	i = 0;
	if (!var[i])
	{
		while(*env[i])	//if no variable is given export prints the array
			printf("%s\n", *env[i]);
		return (0);
	}
	else
	{
		new_value = malloc(ft_strlen(var) + ft_strlen(value) + 2); // +2 for "=" and Nulltermination
		while((*env)[i] != NULL)	//loop to find the variable
		{
			if(ft_strncmp((*env)[i], var, ft_strlen(var)) == 0 && (*env)[i][ft_strlen(var)] == '=')
			{
				free((*env)[i]);
				(*env)[i] = new_value;
				return (0);
			}
		}
		i++;
	}
	// if the loop went through, it means the variable is not in the array and we have to add it
	env_size = i + 1;
	new_env = malloc(sizeof(char *) * env_size);
	if(new_env == NULL)
	{
		perror("minishell: malloc");
		free(new_value);
		return (1);
	}
	j = 0;
	// copy envi into new envi
	while(j < i)
	{
		new_env[j] = (*env)[j];
		j++;
	}
	// Add new value
	new_env[i] = new_value;
	new_env[i + 1] = NULL;
	free_array(*env);
	*env = new_env;
	return (0);
}

// deletes enviroment variables to the environment array
int ft_unset(char ***env, char **var)
{
    int i;
	int j;

	i = 0;
    while ((*env)[i] != NULL) {
        if (strncmp((*env)[i], var, strlen(var)) == 0 && (*env)[i][strlen(var)] == '=')
		{
            free((*env)[i]);
			j = i;
            while ((*env)[j + 1] != NULL) 	// Shift remaining variables left
			{
                (*env)[j] = (*env)[j + 1];
                j++;
            }
            (*env)[j] = NULL;
            return ;
        }
        i++;
    }
	return (0);
}

// Copies the environment from main
char **copy_environ(char **env)
{
	int count;
	char **env_copy;
	int i ;

	count = 0;
	while(env[count] != NULL)
		count++;
	if (count == 0)
		return (NULL);
	env_copy = malloc(sizeof(char *) * (count + 1));
	if (env_copy == NULL)
	{
		perror("minishell: malloc")
		return (NULL);
	}
	i = 0;
	while(i < count)
	{
		env_copy[i] = ft_strdup(env[i]);
		if (!env_copy[i])
		{
			free_array(env_copy, i);
			perror("minishell: malloc");
			return (NULL);
		}
		i++;
	}
	env_copy[i] = NULL;
	return (env_copy);
}

int ft_env(char **env)
{
    int i = 0;

    while (env[i] != NULL)
    {
        if (strchr(env[i], '=') != NULL) // Only print variables with '='
            printf("%s\n", env[i]);
        i++;
    }
	return (0);
}


