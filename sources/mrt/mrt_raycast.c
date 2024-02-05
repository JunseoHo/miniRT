/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:30:32 by jho               #+#    #+#             */
/*   Updated: 2024/02/05 20:22:52 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

// t_vec	mrt_raycast(t_mrt *mrt, t_ray ray)
// {
// 	t_obj	*objs;
// 	t_hit	hit;
// 	t_hit	hit_nearest;
// 	t_vec	light_dir;
// 	t_ray	light_ray;

// 	objs = mrt->objs;
// 	hit_nearest.dist = DIST_MAX;
// 	while (objs != NULL)
// 	{
// 		if (mrt_hit(objs, ray, &hit) && hit.dist < hit_nearest.dist)
// 			hit_nearest = hit;
// 		objs = objs->next;
// 	}
// 	light_dir = vec_norm(vec_sub(mrt->lits->origin, hit.origin));
// 	light_ray = mrt_ray(hit.normal, light_dir);
// 	if (mrt_hit(mrt->objs, light_ray, &hit_nearest) == TRUE)
// 		return (mrt_color(0, 0, 0));
// 	if (hit_nearest.dist != DIST_MAX)
// 		return (mrt_phong(mrt, ray, &hit_nearest));
// 	return (mrt_color(0, 0, 0));
// }

t_vec	mrt_raycast(t_mrt *mrt, t_ray ray)
{
	t_obj	*objs;
	t_hit	hit;
	t_hit	hit_nearest;
	t_vec	light_dir;
	t_ray	light_ray;
	t_obj	*hit_obj;

	objs = mrt->objs;
	hit_obj = objs;
	hit_nearest.dist = DIST_MAX;
	while (objs != NULL)
	{
		if (mrt_hit(objs, ray, &hit) && hit.dist < hit_nearest.dist)
		{
			hit_nearest = hit;
			hit_obj = objs;
		}
		objs = objs->next;
	}
	light_dir = vec_norm(vec_sub(mrt->lits->origin, hit.origin));
	light_ray = mrt_ray(hit.normal, light_dir);
	if (hit_obj != NULL && mrt_hit(hit_obj, light_ray, &hit_nearest) == TRUE)
		return (mrt_color(0, 0, 0));
	if (hit_nearest.dist != DIST_MAX)
		return (mrt_phong(mrt, ray, &hit_nearest));
	return (mrt_color(0, 0, 0));
}