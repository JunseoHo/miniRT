/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_amb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:02:42 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 16:21:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_amb(t_rt *rt, char **tokens)
{
	if (rt->amb != NULL)
		return (0);
	rt->amb = malloc(sizeof(t_amb));
	if (rt->amb == NULL)
		return (0);
	rt->amb->rat = mrt_atof(tokens[1]);
	rt->amb->c = mrt_parse_color(tokens[2]);
	return (rt);
}