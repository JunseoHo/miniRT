/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:33:24 by jho               #+#    #+#             */
/*   Updated: 2024/02/02 17:04:07 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static t_bool	mrt_hit_cone_bottom(t_obj *cn, t_ray ray, t_hit *hit)
{
	t_obj	pl;

	pl.axis = cn->axis;
	pl.origin = vec_add(cn->origin, vec_scale(cn->axis, cn->height * -1));
	if (mrt_hit_plane(&pl, ray, hit))
	{
		if (cn->radius > vec_len(vec_sub(hit->origin, pl.origin)))
		{
			hit->normal = vec_norm(vec_sub(hit->origin, cn->origin));
			hit->albedo = cn->albedo;
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}

static t_bool	mrt_hit_cone_check_height(t_obj *cn, t_vec intersect)
{
	t_vec	hypotenus;
	double	height;

	hypotenus = vec_sub(intersect, cn->origin);
	height = sqrt(pow(vec_len(hypotenus), 2) - pow(cn->radius, 2));
	return (height < cn->height);
}

static t_bool	mrt_hit_cone_side(t_obj *cn, t_ray ray, t_hit *hit)
{
	t_vec	top;
	double	m;
	t_vec	ray_to_top;
	double	coeff[3];
	double	determinant;

	top = vec_add(cn->origin, vec_scale(cn->axis, cn->height * 0.5));
	m = pow(cn->radius, 2) / (cn->height, 2);
	ray_to_top = vec_sub(ray.origin, top);
	coeff[0] = vec_dot(ray.dir, ray.dir)
		- (m * pow(vec_dot(ray.dir, cn->axis), 2))
		- (pow(vec_dot(ray.dir, cn->axis), 2));
	coeff[1] = vec_dot(ray.dir, ray_to_top)
		- (m * vec_dot(ray.dir, cn->axis) * vec_dot(ray_to_top, cn->axis))
		- vec_dot(ray.dir, cn->axis) * vec_dot(ray_to_top, cn->axis);
	coeff[2] = vec_dot(ray_to_top, ray_to_top)
		- (m * pow(vec_dot(ray_to_top, cn->axis), 2))
		- pow(vec_dot(ray_to_top, cn->axis), 2);
	determinant = pow(coeff[1], 2) - (coeff[0] * coeff[2]);
	if (determinant < 0)
		return (FALSE);
	hit->dist = (-coeff[1] - sqrt(determinant)) / coeff[0];
	hit->origin = mrt_ray_at(ray, hit->dist);
	hit->normal = vec_norm(vec_sub(hit->origin, cn->origin));
	hit->albedo = cn->albedo;
	return (TRUE);
}

t_bool	mrt_hit_cone(t_obj *cn, t_ray ray, t_hit *hit)
{
	if (mrt_hit_cone_side(cn, ray, hit))
		return (TRUE);
	return (mrt_hit_cone_bottom(cn, ray, hit));
}
