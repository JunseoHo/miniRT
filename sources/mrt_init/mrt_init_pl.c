/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:11:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:48:34 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_pl(t_geo **geo_list, char **tokens)
{
	t_geo	*geo;
	bool	b_stat;

	geo = mrt_geo_malloc(PL);
	b_stat = true;
	b_stat = (mrt_init_axis(&(geo->pos), tokens[1])
			&& mrt_init_axis(&(geo->ori), tokens[2])
			&& mrt_init_color(&(geo->c), tokens[3]));
	if ((mrt_verify_float_range(geo->ori.x, -1, 1) == false) || (mrt_verify_float_range(geo->ori.y, -1, 1) == false) || (mrt_verify_float_range(geo->ori.z, -1, 1) == false))
		return (false);
	mrt_geo_add_last(geo_list, geo);
	return (b_stat);
}
