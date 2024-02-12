/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:39:57 by jho               #+#    #+#             */
/*   Updated: 2024/02/12 15:09:44 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_bool	mrt_hit_plane(t_obj *pl, t_ray ray, t_hit *hit)
{
	double	numerator;
	double	denominator;
	double	dist;

	numerator = vec_dot(pl->axis, vec_sub(ray.origin, pl->origin)) * -1;
	denominator = vec_dot(pl->axis, ray.dir);
	dist = numerator / denominator;
	if (dist < 0)
		return (FALSE);
	if (dist < DIST_MIN || dist > DIST_MAX)
		return (FALSE);
	hit->dist = dist;
	hit->origin = mrt_ray_at(ray, dist);
	hit->normal = pl->axis;
	if (vec_dot(ray.dir, hit->normal) > 0)
		hit->normal = vec_scale(hit->normal, -1);
	hit->albedo = pl->albedo;
	hit->obj = pl;
	return (TRUE);
}
