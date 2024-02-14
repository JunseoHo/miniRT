/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:30:32 by jho               #+#    #+#             */
/*   Updated: 2024/02/14 14:15:54 by jho              ###   ########.fr       */
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
		if ((objs_cpy != hit->obj && mrt_hit(objs_cpy, light_ray, &dummy_hit)) == TRUE)
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
	t_vec	light_color;

	objs = mrt->objs;
	hit_nearest.dist = DIST_MAX;
	while (objs != NULL)
	{
		if (mrt_hit(objs, ray, &hit) && hit.dist < hit_nearest.dist)
			hit_nearest = hit;
		objs = objs->next;
	}
	if (hit_nearest.dist == DIST_MAX)
		return (vec(0, 0, 0));
	if (mrt_hard_shadow(mrt->objs, mrt->lit, &hit_nearest))
	{
		light_color = vec_scale(mrt->amb.color, mrt->amb.ratio);
		return (vec(light_color.x * hit_nearest.albedo.x,
				light_color.y * hit_nearest.albedo.y,
				light_color.z * hit_nearest.albedo.z));
	}
	return (mrt_phong(mrt, ray, &hit_nearest));
}
