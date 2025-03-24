/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:50:03 by lhaas             #+#    #+#             */
/*   Updated: 2025/03/24 16:02:35 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ft_itoa(last_exit_status)
char	*expand_variable(const char *input, size_t *pos)
{
	size_t	start;
	char	var_name[256];
	char	*expanded_value;
	char	*env_value;
	size_t	i;

	start = *pos + 1;
	i = 0;
	while (input[start] && (ft_isalnum(input[start]) || input[start] == '_')
		&& i < 255)
		var_name[i++] = input[start++];
	var_name[i] = '\0';
	if (i == 0)
		return (ft_strdup(""));
	if (ft_strcmp(var_name, "?") == 0)
		return ("last exit status");
	if (ft_strcmp(var_name, "$") == 0)
		return (ft_itoa(getpid()));
	env_value = getenv(var_name);
	if (env_value)
		expanded_value = ft_strdup(env_value);
	else
		expanded_value = ft_strdup("");
	*pos = start;
	return (expanded_value);
}

char	*find_expanded_value(t_lexer *lexer, char *token_value)
{
	char	*expanded_value;

	expanded_value = expand_variable(lexer->input, &(lexer->pos));
	if (!expanded_value)
		return (NULL);
	token_value = ft_strjoin(token_value, expanded_value);
	free(expanded_value);
	return (token_value);
}

int	is_delimiter(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (0);
	return (1);
}

t_token	*create_delim_token(t_lexer *lexer)
{
	if (lexer->input[lexer->pos] == '|')
		return (lexer->pos++, new_token(TOKEN_PIPE, "|"));
	if (lexer->input[lexer->pos] == '>')
	{
		if (lexer->input[lexer->pos + 1] == '>')
			return (lexer->pos += 2, new_token(TOKEN_APPEND, ">>"));
		return (lexer->pos++, new_token(TOKEN_REDIRECT_OUT, ">"));
	}
	if (lexer->input[lexer->pos] == '<')
	{
		if (lexer->input[lexer->pos + 1] == '<')
			return (lexer->pos += 2, new_token(TOKEN_HEREDOC, "<<"));
		return (lexer->pos++, new_token(TOKEN_REDIRECT_IN, "<"));
	}
	else
		return (NULL);
}

t_token	*lexer(char *line, char **env)
{
	t_lexer	lexer;
	t_token	*tokens;
	t_token	*current_token;

	tokens = NULL;
	current_token = NULL;
	lexer.input = line;
	lexer.pos = 0;
	current_token = lexer_next_token(&lexer, NULL, '\0', NULL);
	while (current_token->type != TOKEN_EOF)
	{
		if (current_token->type == TOKEN_ERROR)
		{
			fprintf(stderr, "Lexer error: %s\n", current_token->value);
			free_tokens(tokens);
			free(current_token);
			return (NULL);
		}
		add_token(&tokens, current_token);
		current_token = lexer_next_token(&lexer, NULL, '\0', NULL);
	}
	add_token(&tokens, current_token);
	return (tokens);
}
