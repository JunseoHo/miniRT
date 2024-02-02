/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:34:12 by jho               #+#    #+#             */
/*   Updated: 2024/02/02 16:35:24 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_obj	*mrt_cone(t_vec center, t_vec axis, double diameter, double height)
{
	t_obj	*cone;

	cone = malloc(sizeof(t_obj));
	if (cone == NULL)
		ft_except("Malloc failed.", errno);
	cone->type = CN;
	cone->origin = center;
	cone->axis = axis;
	cone->radius = diameter / 2;
	cone->height = height;
	cone->albedo = mrt_color(255, 0, 0);
	cone->next = NULL;
	return (cone);
}
