/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:44 by jho               #+#    #+#             */
/*   Updated: 2024/01/24 20:06:28 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_obj	*mrt_plane(t_vec center, t_vec normal)
{
	t_obj	*plane;
	
	plane = malloc(sizeof(t_obj));
	if (plane == NULL)
		ft_except("Malloc failed.", errno);
	plane->type = PLANE;
	plane->origin = center;
	plane->axis = normal;
	plane->albedo = mrt_color(255, 0, 0);
	plane->next = NULL;
	return (plane);
}