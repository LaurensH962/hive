#include "minishell.h"

void	handle_heredoc(int *heredoc_pipe, t_ast *node, t_shell *shell)
{
	if (pipe(heredoc_pipe) == -1)
	{
		perror("minishell: pipe");
		cleanup_shell(shell);
		exit(1);
	}
	write(heredoc_pipe[1], node->redirections->file, strlen(node->redirections->file));
    close(heredoc_pipe[1]);
	dup2(heredoc_pipe[0], STDIN_FILENO);
    close(heredoc_pipe[0]);
}

void	handle_inputfile(int *fd_read, t_ast *node, t_shell *shell)
{
	check_file_access_read(node->redirections->file, shell);
	*fd_read = open(node->redirections->file, O_RDONLY);
	if (*fd_read == -1)
	{
		perror("minishell: open");
		cleanup_shell(shell);
		close(*fd_read);
		exit(1);
	}
	dup2(*fd_read, STDIN_FILENO);
	close(*fd_read);
}

void	handle_outputfile(int *fd_write, t_ast *node, t_shell *shell)
{
	check_file_access_write(node->redirections->file, shell);
	if (node->redirections->type == NODE_APPEND)
		*fd_write = open(node->redirections->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*fd_write = open(node->redirections->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_write == -1)
	{
		perror("minishell: open output file failed");
		cleanup_shell(shell);
		close(*fd_write);
		exit(1);
	}
	dup2(*fd_write, STDOUT_FILENO);
	close(*fd_write);
}

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
		perror("minishell: malloc");
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

/*void	execute_builtin(t_ast *node, t_shell *shell)
{
	char *number = "3";
	if (ft_strcmp(node->cmd ,"echo") == 0)
		exit(ft_echo(node->args, node->args[1]));
	else if (ft_strcmp(node->cmd , "cd") == 0)
		exit(ft_cd(node->args[1]));
	else if (ft_strcmp(node->cmd ,"exit") == 0)
		ft_exit(node->cmd);
	else if (ft_strcmp(node->cmd  ,"pwd") == 0)
		exit(ft_pwd());
	else if (ft_strcmp(node->cmd , "export") == 0)
		exit(ft_export(&shell->env, node->args, &number));
	else if (ft_strcmp(node->cmd , "unset") == 0)
		exit(ft_unset(&shell->env, node->args));
	else if (ft_strcmp(node->cmd ,"env") == 0)
		exit(ft_env(shell->env));
}

int	check_if_builtin(t_ast *node)
{
	if (ft_strcmp(node->cmd ,"echo") == 0)
		return (1);
	else if (ft_strcmp(node->cmd , "cd") == 0)
		return (1);
	else if (ft_strcmp(node->cmd ,"exit") == 0)
		return (1);
	else if (ft_strcmp(node->cmd  ,"pwd") == 0)
		return (1);
	else if (ft_strcmp(node->cmd , "export") == 0)
		return (1);
	else if (ft_strcmp(node->cmd , "unset") == 0)
		return (1);
	else if (ft_strcmp(node->cmd ,"env") == 0)
		return (1);
	else
		return (0);
}*/