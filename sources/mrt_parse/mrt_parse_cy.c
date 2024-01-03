/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:42:31 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:43:15 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_cy(t_rt *rt, char **tokens)
{
	t_geo	*geo;

	geo = mrt_geo_malloc(CY);
	geo->pos = mrt_parse_axis(tokens[1]);
	geo->ori = mrt_parse_axis(tokens[2]);
	geo->d = mrt_atof(tokens[3]);
	geo->h = mrt_atof(tokens[4]);
	geo->c = mrt_parse_color(tokens[5]);
	mrt_rt_add_geo(rt, geo);
	return (1);
}
