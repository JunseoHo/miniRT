/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:33:24 by jho               #+#    #+#             */
/*   Updated: 2024/02/14 18:07:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static t_bool	mrt_hit_cone_bottom(t_obj *cn, t_ray ray, t_hit *hit)
{
	t_obj	pl;

	pl.axis = cn->axis;
	pl.origin = vec_add(cn->origin, vec_scale(cn->axis, cn->height * -0.5));
	if (mrt_hit_plane(&pl, ray, hit))
	{
		if (cn->radius > vec_len(vec_sub(hit->origin, pl.origin)))
		{
			hit->normal = vec_norm(vec_scale(cn->axis, -1));
			hit->albedo = cn->albedo;
			hit->obj = cn;
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}

static t_bool	mrt_hit_cone_check_height(t_obj *cn, t_vec intersect)
{
	t_vec	top;
	double	hypotenus;
	double	dist_from_origin_to_top;
	double	dist_from_origin_to_intersect;
	double	height;

	top = vec_add(cn->origin, vec_scale(cn->axis, cn->height * 0.5));
	hypotenus = vec_len(vec_sub(intersect, top));
	dist_from_origin_to_top = vec_len(vec_sub(top, cn->origin));
	dist_from_origin_to_intersect = vec_len(vec_sub(intersect, cn->origin));
	if (dist_from_origin_to_top < dist_from_origin_to_intersect && \
	vec_dot(cn->axis, vec_sub(intersect, cn->origin)) > 0)
		return (FALSE);
	return (sqrt(pow(cn->radius, 2) + pow(cn->height, 2)) > hypotenus);
}

static	void	mrt_init_coeff(double coeff[3], t_obj *cn, t_ray ray)
{
	t_vec	top;
	double	m;
	t_vec	ray_to_top;

	top = vec_add(cn->origin, vec_scale(cn->axis, cn->height * 0.5));
	m = pow(cn->radius, 2) / pow(cn->height, 2);
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
}

static t_bool	mrt_hit_cone_side(t_obj *cn, t_ray ray, t_hit *hit)
{
	double	coeff[3];
	double	determinant;
	t_vec	top;
	t_vec	cp;
	double	k;

	mrt_init_coeff(coeff, cn, ray);
	determinant = pow(coeff[1], 2) - (coeff[0] * coeff[2]);
	if (determinant < 0)
		return (FALSE);
	hit->dist = (-coeff[1] - sqrt(determinant)) / coeff[0];
	hit->origin = mrt_ray_at(ray, hit->dist);
	if (!mrt_hit_cone_check_height(cn, hit->origin))
		return (FALSE);
	top = vec_add(cn->origin, vec_scale(cn->axis, 0.5 * cn->height));
	cp = vec_sub(hit->origin, top);
	k = pow(vec_len(cp), 2) / vec_dot(cp, vec_norm(vec_scale(cn->axis, -1)));
	hit->normal = vec_norm(vec_sub(cp, vec_scale(vec_scale(cn->axis, -1), k)));
	hit->albedo = cn->albedo;
	hit->obj = cn;
	return (TRUE);
}

t_bool	mrt_hit_cone(t_obj *cn, t_ray ray, t_hit *hit)
{
	if (mrt_hit_cone_side(cn, ray, hit))
		return (TRUE);
	return (mrt_hit_cone_bottom(cn, ray, hit));
}
