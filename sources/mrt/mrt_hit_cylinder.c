/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:42:25 by jho               #+#    #+#             */
/*   Updated: 2024/02/20 16:17:05 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static t_bool	mrt_hit_cylinder_top(t_obj *cy, t_ray ray, t_hit *hit)
{
	t_obj	pl;

	pl.axis = cy->axis;
	pl.origin = vec_add(cy->origin, vec_scale(cy->axis, cy->height * 1));
	if (mrt_hit_plane(&pl, ray, hit))
	{
		if (cy->radius > vec_len(vec_sub(hit->origin, pl.origin)))
		{
			hit->normal = vec_norm(cy->axis);
			if (vec_dot(ray.dir, hit->normal) > 0)
				hit->normal = vec_scale(hit->normal, -1);
			hit->albedo = cy->albedo;
			hit->obj = cy;
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}

static t_bool	mrt_hit_cylinder_bottom(t_obj *cy, t_ray ray, t_hit *hit)
{
	t_obj	pl;

	pl.axis = cy->axis;
	pl.origin = vec_add(cy->origin, vec_scale(cy->axis, cy->height * -1));
	if (mrt_hit_plane(&pl, ray, hit))
	{
		if (cy->radius > vec_len(vec_sub(hit->origin, pl.origin)))
		{
			hit->normal = vec_norm(vec_scale(cy->axis, -1));
			if (vec_dot(ray.dir, hit->normal) > 0)
				hit->normal = vec_scale(hit->normal, -1);
			hit->albedo = cy->albedo;
			hit->obj = cy;
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}

t_bool	mrt_hit_cylinder(t_obj *cy, t_ray ray, t_hit *hit)
{
	if (mrt_hit_cylinder_side(cy, ray, hit))
		return (TRUE);
	if (mrt_hit_cylinder_top(cy, ray, hit))
		return (TRUE);
	return (mrt_hit_cylinder_bottom(cy, ray, hit));
}
