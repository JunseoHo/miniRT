/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:16:20 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:47:51 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_cy(t_geo **geo_list, char **tokens)
{
	t_geo	*geo;
	bool	b_stat;

	geo = mrt_geo_malloc(CY);
	b_stat = (mrt_init_axis(&(geo->pos), tokens[1])
			&& mrt_init_axis(&(geo->ori), tokens[2])
			&& mrt_init_float(&(geo->d), tokens[3])
			&& mrt_init_float(&(geo->h), tokens[4])
			&& mrt_init_color(&(geo->c), tokens[5]));
	if ((mrt_verify_float_range(geo->ori.x, -1, 1) == false) || (mrt_verify_float_range(geo->ori.y, -1, 1) == false) || (mrt_verify_float_range(geo->ori.z, -1, 1) == false))
		return (false);
	mrt_geo_add_last(geo_list, geo);
	return (b_stat);
}