/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:42:25 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 21:14:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

//t_bool	mrt_hit_cylinder_check_height(t_obj *cy, t_vec intersect)
//{
//	t_vec	hypotenus;
//	double	height;

//	hypotenus = vec_sub(intersect, cy->origin);
//	height = sqrt(pow(vec_len(hypotenus), 2) - pow(cy->radius, 2));
//	return (height < cy->height);
//}

//t_bool	mrt_hit_cylinder_side(t_obj *cy, t_ray ray, t_hit *hit)
//{
//	double	coeff[3];
//	t_vec	center;
//	t_vec	ray_to_base;
//	double	determinant;
//	double	t;

//	center = vec_add(cy->origin, vec_scale(cy->axis, -0.5 * cy->height));
//	ray_to_base = vec_sub(ray.origin, center);
//	coeff[0] = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->axis), 2);
//	coeff[1] = 2 * (vec_dot(ray.dir, ray_to_base)
//			- vec_dot(ray.dir, cy->axis) * vec_dot(ray_to_base, cy->axis));
//	coeff[2] = vec_dot(ray_to_base, ray_to_base)
//		- pow(vec_dot(ray_to_base, cy->axis), 2)
//		- pow(cy->radius, 2);
//	determinant = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
//	t = (-coeff[1] - sqrt(determinant)) / 2 * coeff[0];
//	if (determinant < 0)
//		return (false);
//	if (!mrt_hit_cylinder_check_height(cy, mrt_ray_at(ray, t)))
//		return (false);
//	hit->len = (-coeff[1] - sqrt(determinant)) / 2 * coeff[0];
//	hit->origin = mrt_ray_at(ray, hit->len);
//	hit->normal = vec_norm(vec_sub(hit->origin, cy->origin));
//	hit->b_front = vec_dot(ray.dir, hit->normal) < 0;
//	if (!hit->b_front)
//		hit->normal = vec_scale(hit->normal, -1);
//	hit->albedo = cy->albedo;
//	return (TRUE);
//}

t_bool	mrt_hit_cylinder(t_obj *cy, t_ray ray, t_hit *hit)
{
	//if (!mrt_hit_cylinder_side(cy, ray, hit))
	//	return (false);
	return (TRUE);
}
