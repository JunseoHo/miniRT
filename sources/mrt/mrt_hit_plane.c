/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:39:57 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 19:38:36 by jho              ###   ########.fr       */
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
	hit->dist = dist;
	hit->origin = mrt_ray_at(ray, dist);
	hit->normal = pl->axis;
	if (vec_dot(ray.dir, hit->normal) > 0)
		hit->normal = vec_scale(hit->normal, -1);
	hit->albedo = pl->albedo;
	return (TRUE);
}
