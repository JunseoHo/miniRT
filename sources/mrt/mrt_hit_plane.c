/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:39:57 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:08:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_hit_plane(t_obj *pl, t_ray ray, t_hit *hit)
{
	double	numerator;
	double	denominator;
	double	t;

	numerator = vec_dot(pl->axis, vec_sub(ray.origin, pl->origin)) * -1;
	denominator = vec_dot(pl->axis, ray.dir);
	t = numerator / denominator;
	if (t < 0)
		return (false);
	hit->len = t;
	hit->origin = mrt_ray_at(ray, t);
	hit->normal = pl->axis;
	hit->albedo = pl->albedo;
	return (true);
}
