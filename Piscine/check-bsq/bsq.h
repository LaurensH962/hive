/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:33:32 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:37:38 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct elements
{
	int		row;
	int		col;
	char	fill;
	char	empt;
	char	obs;
}			t_elems;

typedef struct square
{
	int		x;
	int		y;
	int		length;
}			t_sqr;

typedef struct xandi
{
	int		x;
	int		i;
}			t_xi;

#endif
