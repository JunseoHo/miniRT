/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:30:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/24 20:05:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_vec	mrt_raycast(t_mrt *mrt, t_ray ray)
{
	t_obj	*objs;
	t_hit	hit;
	t_hit	hit_nearest;
	double	t_nearest;

	objs = mrt->objs;
	hit_nearest.t = INFINITY;
	while (objs != NULL)
	{
		if (mrt_hit(objs, ray, &hit) && hit.t < hit_nearest.t)
			hit_nearest = hit;
		objs = objs->next;
	}
	if (hit_nearest.t != INFINITY)
		return (mrt_phong(mrt, ray, &hit_nearest));
	return (mrt_color(0, 0, 0));
}
