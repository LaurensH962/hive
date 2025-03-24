/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:45:31 by lhaas             #+#    #+#             */
/*   Updated: 2025/03/20 12:49:58 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

bool	is_redirect(t_token_type type)
{
	return (type == TOKEN_REDIRECT_OUT || type == TOKEN_REDIRECT_IN
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}
