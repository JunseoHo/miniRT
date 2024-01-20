/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:01:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 05:18:22 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_hit(t_obj *obj, t_ray ray)
{
	t_hit	hit;

	if (obj->type == SPHERE)
		return (mrt_hit_sphere(obj, ray, &hit));
	else if (obj->type == PLANE)
		printf("Hit plane.\n"); /* Not implement. */
	else if (obj->type == CYLINDER)
		printf("Hit cylinder.\n"); /* Not implement. */
	return (false);
}