/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:42:25 by jho               #+#    #+#             */
/*   Updated: 2024/02/14 14:08:41 by jho              ###   ########.fr       */
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
			hit->normal = vec_norm(vec_sub(hit->origin, cy->origin));
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
			hit->normal = vec_norm(vec_sub(hit->origin, cy->origin));
			hit->albedo = cy->albedo;
			hit->obj = cy;
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}

static t_bool	mrt_hit_cylinder_check_height(t_obj *cy, t_vec intersect)
{
	t_vec	hypotenus;
	double	height;

	hypotenus = vec_sub(intersect, cy->origin);
	height = sqrt(pow(vec_len(hypotenus), 2) - pow(cy->radius, 2));
	return (height < cy->height);
}

static t_bool	mrt_hit_cylinder_side(t_obj *cy, t_ray ray, t_hit *hit)
{
	t_vec	base;
	t_vec	ray_to_base;
	double	coeff[3];
	double	determinant;

	base = vec_sub(cy->origin, vec_scale(cy->axis, 0.5 * cy->height));
	ray_to_base = vec_sub(ray.origin, base);
	coeff[0] = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->axis), 2);
	coeff[1] = vec_dot(ray.dir, ray_to_base)
		- vec_dot(ray.dir, cy->axis) * vec_dot(ray_to_base, cy->axis);
	coeff[2] = vec_dot(ray_to_base, ray_to_base)
		- pow(vec_dot(ray_to_base, cy->axis), 2)
		- pow(cy->radius, 2);
	determinant = pow(coeff[1], 2) - (coeff[0] * coeff[2]);
	if (determinant < 0)
		return (FALSE);
	hit->dist = (-coeff[1] - sqrt(determinant)) / coeff[0];
	hit->origin = mrt_ray_at(ray, hit->dist);
	if (!mrt_hit_cylinder_check_height(cy, hit->origin))
		return (FALSE);
	hit->normal = vec_norm(vec_sub(hit->origin, cy->origin));
	hit->albedo = cy->albedo;
	hit->obj = cy;
	return (TRUE);
}

t_bool	mrt_hit_cylinder(t_obj *cy, t_ray ray, t_hit *hit)
{
	if (mrt_hit_cylinder_side(cy, ray, hit))
		return (TRUE);
	if (mrt_hit_cylinder_top(cy, ray, hit))
		return (TRUE);
	return (mrt_hit_cylinder_bottom(cy, ray, hit));
}
