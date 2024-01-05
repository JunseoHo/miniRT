/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:57:00 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:56:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_sp(t_geo **geo_list, char **tokens)
{
	t_geo	*geo;
	bool	b_stat;

	geo = mrt_geo_malloc(SP);
	b_stat = (mrt_init_axis(&(geo->pos), tokens[1])
			&& mrt_init_float(&(geo->d), tokens[2])
			&& mrt_init_color(&(geo->c), tokens[3]));
	mrt_geo_add_last(geo_list, geo);
	return (b_stat);
}
