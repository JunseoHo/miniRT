/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:15:43 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 14:20:42 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_obj	*mrt_sphere(t_vec center, double diameter)
{
	t_obj	*sp;

	sp = malloc(sizeof(t_obj));
	if (sp == NULL)
		ft_except("Malloc failed.", errno);
	sp->type = SP;
	sp->origin = center;
	sp->radius = diameter / 2;
	sp->albedo = mrt_color(255, 0, 0);
	sp->next = NULL;
	return (sp);
}
