/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:05:04 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:08:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_hit_sphere(t_obj *sphere, t_ray ray, t_hit *hit)
{
	t_vec	origin_center;
	double	coeff[3];
	double	discriminant;
	double	root[2];
	
	origin_center = vec_sub(ray.origin, sphere->origin);
	coeff[0] = vec_dot(ray.dir, ray.dir);
	coeff[1] = vec_dot(origin_center, ray.dir);
	coeff[2] = vec_dot(origin_center, origin_center) - pow(sphere->radius, 2);
	discriminant = pow(coeff[1], 2) - coeff[0] * coeff[2];
	if (discriminant < 0)
		return (false);
	root[0] = (-coeff[1] - sqrt(discriminant)) / coeff[0];
	root[1] = (-coeff[1] + sqrt(discriminant)) / coeff[0];
	if ((root[0] < T_MIN || root[0] > T_MAX) && (root[1] < T_MIN || root[1] > T_MAX))
		return (false);
	hit->len = root[0];
	hit->origin = mrt_ray_at(ray, root[0]);
	hit->normal = vec_norm(vec_sub(hit->origin, sphere->origin));
	hit->b_front = vec_dot(ray.dir, hit->normal) < 0;
	if (!hit->b_front)
		hit->normal = vec_scale(hit->normal, -1);
	hit->albedo = sphere->albedo;
	return (true);
}