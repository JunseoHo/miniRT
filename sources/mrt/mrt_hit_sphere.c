/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:05:04 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 04:20:40 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_hit_sphere(t_obj *sphere, t_ray ray)
{
	t_vec	origin_center;
	double	coeff[3];
	double	discriminant;
	
	origin_center = vec_sub(ray.origin, sphere->origin);
	coeff[0] = vec_dot(ray.dir, ray.dir);
	coeff[1] = 2.0 * vec_dot(origin_center, ray.dir);
	coeff[2] = vec_dot(origin_center, origin_center) - pow(sphere->radius, 2);
	discriminant = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
	if (discriminant < 0)
		return (false);
	return (true);
}