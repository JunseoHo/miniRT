/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:30:32 by jho               #+#    #+#             */
/*   Updated: 2024/02/02 13:57:27 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_vec	mrt_raycast(t_mrt *mrt, t_ray ray)
{
	t_obj	*objs;
	t_hit	hit;
	t_hit	hit_nearest;

	objs = mrt->objs;
	hit_nearest.dist = DIST_MAX;
	while (objs != NULL)
	{
		if (mrt_hit(objs, ray, &hit) && hit.dist < hit_nearest.dist)
			hit_nearest = hit;
		objs = objs->next;
	}
	if (hit_nearest.dist != DIST_MAX)
		return (mrt_phong(mrt, ray, &hit_nearest));
	return (mrt_color(0, 0, 0));
}
