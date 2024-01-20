/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:30:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 04:18:35 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

int	mrt_raycast(t_mrt *mrt, t_ray ray)
{
	t_obj	*objs;

	objs = mrt->objs;
	while (objs != NULL)
	{
		if (mrt_hit(objs, ray))
			return (objs->color);
		objs = objs->next;
	}
	return (BACKGROUND_COLOR);
}