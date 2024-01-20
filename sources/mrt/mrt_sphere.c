/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:15:43 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 05:51:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_obj	*mrt_sphere(t_vec center, double diameter)
{
	t_obj	*sphere;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		ft_except("Malloc failed.", errno);
	sphere->type = SPHERE;
	sphere->origin = center;
	sphere->radius = diameter / 2;
	sphere->albedo = mrt_color(255, 0, 0);
	sphere->next = NULL;
	return (sphere);
}