/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:35:51 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:06:09 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_obj	*mrt_cylinder(t_vec center, t_vec axis, double diameter, double height)
{
	t_obj	*cylinder;

	cylinder = malloc(sizeof(t_obj));
	if (cylinder == NULL)
		ft_except("Malloc failed.", errno);
	cylinder->type = CY;
	cylinder->origin = center;
	cylinder->axis = axis;
	cylinder->radius = diameter / 2;
	cylinder->height = height;
	cylinder->albedo = mrt_color(255, 0, 0);
	cylinder->next = NULL;
	return (cylinder);
}