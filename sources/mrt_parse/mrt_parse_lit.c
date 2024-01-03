/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_lit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:47:48 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 09:16:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_lit(t_rt *rt, char **tokens)
{
	if (rt->lit != NULL)
		return (0);
	rt->lit = malloc(sizeof(t_lit));
	if (rt->lit == NULL)
		mrt_exit("malloc failed.");
	rt->lit->pos = mrt_parse_axis(tokens[1]);
	rt->lit->br = mrt_atof(tokens[2]);
	return (1);
}
