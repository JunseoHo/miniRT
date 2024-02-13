/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:30:32 by jho               #+#    #+#             */
/*   Updated: 2024/02/13 20:38:01 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_bool	mrt_hard_shadow(t_obj *objs, t_lit lit, t_hit *hit)
{
	t_obj	*objs_cpy;
	t_vec	light_dir;
	t_ray	light_ray;
	t_hit	dummy_hit;

	objs_cpy = objs;
	light_dir = vec_norm(vec_sub(lit.origin, hit->origin));
	light_ray = mrt_ray(hit->origin, light_dir);
	if (vec_dot(light_dir, hit->normal) < 0)
		return (FALSE);
	while (objs_cpy != NULL)
	{
		if (mrt_hit(objs_cpy, light_ray, &dummy_hit) == TRUE)
			return (TRUE);
		objs_cpy = objs_cpy->next;
	}
	return (FALSE);
}

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
	t_vec color;
	color = vec(0, 0, 0);
	color = vec_add(color, vec_scale(mrt->amb.color, mrt->amb.ratio));
	if (hit_nearest.dist == DIST_MAX
		|| mrt_hard_shadow(mrt->objs, mrt->lit, &hit_nearest))
		return (vec(hit_nearest.albedo.x * mrt->amb.ratio, hit_nearest.albedo.y * mrt->amb.ratio, hit_nearest.albedo.z * mrt->amb.ratio));
		// return (mrt_color(0, 0, 0));
	return (mrt_phong(mrt, ray, &hit_nearest));
}
