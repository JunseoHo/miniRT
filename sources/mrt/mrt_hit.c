/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:01:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 18:46:23 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_bool	mrt_hit(t_obj *obj, t_ray ray, t_hit *hit)
{
	if (obj->type == SP)
		return (mrt_hit_sphere(obj, ray, hit));
	else if (obj->type == PL)
		return (mrt_hit_plane(obj, ray, hit));
	else if (obj->type == CY)
		return (mrt_hit_cylinder(obj, ray, hit));
	return (FALSE);
}
