/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:35:51 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 17:11:38 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

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
