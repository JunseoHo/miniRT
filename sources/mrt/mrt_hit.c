/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:01:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/24 20:43:42 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_hit(t_obj *obj, t_ray ray, t_hit *hit)
{
	if (obj->type == SPHERE)
		return (mrt_hit_sphere(obj, ray, hit));
	else if (obj->type == PLANE)
		return (mrt_hit_plane(obj, ray, hit));
	else if (obj->type == CYLINDER)
		return (mrt_hit_cylinder(obj, ray, hit));
	return (false);
}