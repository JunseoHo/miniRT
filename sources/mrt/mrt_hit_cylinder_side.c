/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cylinder_side.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:14:21 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/20 16:17:08 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static	void	init_eqn(t_obj *cy, t_ray ray, double eqn[4], t_vec ray_to_base)
{
	eqn[0] = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->axis), 2);
	eqn[1] = vec_dot(ray.dir, ray_to_base)
		- vec_dot(ray.dir, cy->axis) * vec_dot(ray_to_base, cy->axis);
	eqn[2] = vec_dot(ray_to_base, ray_to_base)
		- pow(vec_dot(ray_to_base, cy->axis), 2)
		- pow(cy->radius, 2);
	eqn[3] = pow(eqn[1], 2) - (eqn[0] * eqn[2]);
}

static	void	init_root(double eqn[4], double root[2])
{
	root[0] = (-eqn[1] - sqrt(eqn[3])) / eqn[0];
	root[1] = (-eqn[1] + sqrt(eqn[3])) / eqn[0];
}

static t_bool	mrt_hit_cylinder_check_height(t_obj *cy, t_vec intersect)
{
	t_vec	hypotenus;
	double	height;
	double	k;

	hypotenus = vec_sub(intersect, cy->origin);
	k = pow(vec_len(hypotenus), 2) - pow(cy->radius, 2);
	if (k < 0)
		return (TRUE);
	height = sqrt(k);
	return (height < cy->height);
}

t_bool	mrt_hit_cylinder_side(t_obj *cy, t_ray ray, t_hit *hit)
{
	t_vec	base;
	t_vec	ray_to_base;
	double	eqn[4];
	double	root[2];

	base = vec_sub(cy->origin, vec_scale(cy->axis, 0.5 * cy->height));
	ray_to_base = vec_sub(ray.origin, base);
	init_eqn(cy, ray, eqn, ray_to_base);
	if (eqn[3] < 0)
		return (FALSE);
	init_root(eqn, root);
	if (root[0] < 0)
		root[0] = root[1];
	hit->dist = root[0];
	hit->origin = mrt_ray_at(ray, hit->dist);
	if (!mrt_hit_cylinder_check_height(cy, hit->origin))
		return (FALSE);
	ray_to_base = vec_sub(hit->origin, base);
	hit->normal = vec_norm(vec_sub(ray_to_base,
				vec_scale(cy->axis, vec_dot(ray_to_base, cy->axis))));
	if (vec_dot(ray.dir, hit->normal) > 0)
		hit->normal = vec_scale(hit->normal, -1);
	hit->albedo = cy->albedo;
	hit->obj = cy;
	return (TRUE);
}
