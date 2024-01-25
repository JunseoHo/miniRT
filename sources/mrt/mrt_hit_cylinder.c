/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:42:25 by jho               #+#    #+#             */
/*   Updated: 2024/01/25 15:21:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_hit_cylinder(t_obj *cy, t_ray ray, t_hit *hit)
{
	double	coeff[3];
	t_vec	centers[2];
	t_vec	ray_to_base;
	double	determinant;
	double	root[2];

	centers[0] = vec_add(cy->origin, vec_scale(cy->axis, -0.5 * cy->height));
	centers[1] = vec_add(cy->origin, vec_scale(cy->axis, 0.5 * cy->height));
	ray_to_base = vec_sub(ray.origin, centers[0]);
	coeff[0] = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->axis), 2);
	coeff[1] = 2 * (vec_dot(ray.dir, ray_to_base)
			- vec_dot(ray.dir, cy->axis) * vec_dot(ray_to_base, cy->axis));
	coeff[2] = vec_dot(ray_to_base, ray_to_base)
		- pow(vec_dot(ray_to_base, cy->axis), 2)
		- pow(cy->radius, 2);
	determinant = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
	if (determinant < 0)
		return (false);
	root[0] = (-coeff[1] - sqrt(determinant)) / 2 * coeff[0];
	hit->t = root[0];
	hit->origin = mrt_ray_at(ray, root[0]);
	hit->normal = vec_norm(vec_sub(hit->origin, cy->origin));
	hit->b_front = vec_dot(ray.dir, hit->normal) < 0;
	if (!hit->b_front)
		hit->normal = vec_scale(hit->normal, -1);
	hit->albedo = cy->albedo;
	return (true);
}
