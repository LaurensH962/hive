/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:58:55 by lhaas             #+#    #+#             */
/*   Updated: 2025/03/24 16:05:12 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_IN,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_ENV_VAR,
	TOKEN_EXIT_STATUS,
	TOKEN_ERROR,
	TOKEN_EOF
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
}						t_token;

typedef struct s_lexer
{
	char				*input;
	size_t				pos;
}						t_lexer;

// lexing
t_token					*new_token(t_token_type type, char *value);
void					add_token(t_token **head, t_token *new);
void					free_tokens(t_token *head);
void					print_tokens(t_token *tokens);
t_token					*lexer_next_token(t_lexer *lexer, t_token *temp_token, char quote_char, char *token_value);
t_token					*lexer(char *line);

// parsing
typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIRECT_OUT,
	NODE_REDIRECT_IN,
	NODE_APPEND,
	NODE_HEREDOC
}						t_node_type;

typedef struct s_redirect
{
	t_node_type			type;
	char				*file;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_ast
{
	t_node_type			type;
	char				*cmd;
	char				*cmd_path;
	char				**args;
	t_redirect			*redirections;
	struct s_ast		*left;
	struct s_ast		*right;
}						t_ast;

typedef struct s_shell
{
	char	**env;
	t_ast	*node;
	int		status_last_command;
	
}				t_shell;

t_ast					*parse(t_token *tokens);

//commmand

char	**copy_environ(char **env);
void	execute_pipeline(t_shell *shell);
void	handle_heredoc(int *heredoc_pipe, t_ast *node, t_shell *shell);
void	handle_inputfile(int *fd_read, t_ast *node, t_shell *shell);
void	handle_outputfile(int *fd_write, t_ast *node, t_shell *shell);
void	check_file_access_read(char *filename, t_shell *shell);
void	check_file_access_write(char *filename, t_shell *shell);
void	check_command_access(t_ast *node, t_shell *shell);
void	report_error(const char *filename, const char *err_msg);
//void	execute_builtin(t_ast *node, t_shell *shell);
//int		check_if_builtin(t_ast *node);
void    handle_redirections(t_ast *node, int in_fd, int out_fd, t_shell *shell);
void    execute_command(t_shell *shell, t_ast *node, int in_fd, int out_fd);
void	execute_ast(t_shell *shell, t_ast *node, int in_fd, int out_fd);
void	cleanup_shell(t_shell *shell);
void	free_array(char **array, int len);
char	*get_command_path(char *cmd, char **envp, int *fail_flag);
void	set_command_path(t_ast *node, t_shell *shell);

//builtins

/*int ft_export(char ***env, char **var, char **value);
int ft_unset(char ***env, char **var);
int ft_env(char **env);
void free_array(char **array, int len);
int is_number(const char *str);
int ft_echo(char **args, char *arg);
int ft_cd(char *path);
void ft_exit(char *arg);
int ft_pwd(void);*/

// printing
void					print_tokens(t_token *tokens);
void					print_ast(t_ast *node, int level);

#endif
