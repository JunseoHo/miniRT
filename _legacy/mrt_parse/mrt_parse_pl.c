/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:42:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_pl(t_rt *rt, char **tokens)
{
	t_geo	*geo;

	geo = mrt_geo_malloc(PL);
	geo->pos = mrt_parse_axis(tokens[1]);
	geo->ori = mrt_parse_axis(tokens[2]);
	geo->c = mrt_parse_color(tokens[3]);
	mrt_rt_add_geo(rt, geo);
	return (1);
}
