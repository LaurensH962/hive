/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:24:24 by lhaas             #+#    #+#             */
/*   Updated: 2025/03/20 17:27:37 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*find_expanded_value(t_lexer *lexer, char *token_value);
int				is_delimiter(char c);
t_token			*create_delim_token(t_lexer *lexer);

t_token	*new_token(t_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
	{
		perror("Failed to allocate token");
		return (NULL);
	}
	token->type = type;
	if (value)
		token->value = ft_strdup(value);
	else
		token->value = NULL;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **head, t_token *new)
{
	t_token	*temp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	free_tokens(t_token *head)
{
	t_token	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->value);
		free(temp);
	}
}

/* len = ft_strlen(token_value);
if	((token_value[0] == '\'' && token_value[len - 1] == '\'')
	|| (token_value[0] == '"' && token_value[len - 1] == '"'))
{
	cleaned_value = ft_strndup(token_value + 1, len - 2);
	free(token_value);
	token_value = cleaned_value;
} */
// size_t	len;
// char	*cleaned_value;
static t_token	*inner_loop( int *pos, char *quote_char,
		char **token_value, t_lexer *lexer)
{
	while (lexer->input[*pos])
	{
		if ((lexer->input[*pos] == '"' || lexer->input[*pos] == '\'')
			&& (*quote_char == lexer->input[*pos] || *quote_char == 0))
		{
			if (*quote_char == lexer->input[*pos])
				*quote_char = 0;
			else if (*quote_char == 0)
				*quote_char = lexer->input[*pos];
			(*pos)++;
			continue ;
		}
		else if (lexer->input[*pos] == '$' && *quote_char != '\'')
		{
			*token_value = find_expanded_value(lexer, *token_value);
			if (!*token_value)
				return (new_token(TOKEN_ERROR, "Variable expansion error"));
			continue ;
		}
		else if (!*quote_char && (ft_isspace(lexer->input[*pos])
				|| !is_delimiter(lexer->input[*pos])))
			break ;
		*token_value = ft_strncat(*token_value, &lexer->input[*pos], 1);
		(*pos)++;
	}
	return (NULL);
}

t_token	*lexer_next_token(t_lexer *lexer, t_token *temp_token, char quote_char,
		char *token_value)
{
	while (lexer->input[lexer->pos])
	{
		if (!quote_char && ft_isspace(lexer->input[lexer->pos]))
		{
			lexer->pos++;
			continue ;
		}
		if (!quote_char)
		{
			temp_token = create_delim_token(lexer);
			if (temp_token)
				return (temp_token);
		}
		token_value = ft_strdup("");
		temp_token = inner_loop( (int *)&lexer->pos, &quote_char,
				&token_value, lexer);
		if (temp_token)
			return (temp_token);
		if (quote_char)
			return (free(token_value), new_token(TOKEN_ERROR,
					"Unclosed quote"));
		return (new_token(TOKEN_WORD, token_value));
	}
	return (new_token(TOKEN_EOF, NULL));
}
