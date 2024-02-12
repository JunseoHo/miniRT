/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:05:04 by jho               #+#    #+#             */
/*   Updated: 2024/02/12 15:09:25 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static void	mrt_hit_sphere_coeff(t_obj *sp, t_ray ray, double *coeff)
{
	t_vec	ray_to_origin;

	ray_to_origin = vec_sub(ray.origin, sp->origin);
	coeff[0] = vec_dot(ray.dir, ray.dir);
	coeff[1] = vec_dot(ray_to_origin, ray.dir);
	coeff[2] = vec_dot(ray_to_origin, ray_to_origin) - pow(sp->radius, 2);
}

static void	mrt_hit_sphere_init(t_hit *hit, t_obj *sp, double *root, t_ray ray)
{
	hit->dist = root[0];
	hit->origin = mrt_ray_at(ray, root[0]);
	hit->normal = vec_norm(vec_sub(hit->origin, sp->origin));
	if (vec_dot(ray.dir, hit->normal) > 0)
		hit->normal = vec_scale(hit->normal, -1);
	hit->albedo = sp->albedo;
	hit->obj = sp;
}

t_bool	mrt_hit_sphere(t_obj *sp, t_ray ray, t_hit *hit)
{
	double	coeff[3];
	double	discriminant;
	double	root[2];

	mrt_hit_sphere_coeff(sp, ray, coeff);
	discriminant = pow(coeff[1], 2) - coeff[0] * coeff[2];
	if (discriminant < 0)
		return (FALSE);
	root[0] = (-coeff[1] - sqrt(discriminant)) / coeff[0];
	root[1] = (-coeff[1] + sqrt(discriminant)) / coeff[0];
	if ((root[0] < DIST_MIN || root[0] > DIST_MAX)
		&& (root[1] < DIST_MIN || root[1] > DIST_MAX))
		return (FALSE);
	mrt_hit_sphere_init(hit, sp, root, ray);
	return (TRUE);
}
