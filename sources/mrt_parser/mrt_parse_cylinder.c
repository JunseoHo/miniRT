/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:55:33 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 14:04:11 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_obj	*init_sphere(void)
{
	t_obj	*sphere;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		ft_except("Malloc failed.", errno);
	sphere->type = CY;
	sphere->next = NULL;
	return (sphere);
}

t_bool	mrt_parse_cylinder(t_obj **objs, char *line)
{
	t_obj	*sphere;

	sphere = init_sphere();
	if (mrt_parse_vector(&(sphere->origin), line, 1) == FALSE)
		return (FALSE);
	if (mrt_parse_vector(&(sphere->axis), line, 2) == FALSE)
		return (FALSE);
	sphere->axis = vec_norm(sphere->axis);
	if (mrt_parse_double(&(sphere->radius), line, '\0', 3) == FALSE)
		return (FALSE);
	sphere->radius /= 2;
	if (mrt_parse_double(&(sphere->height), line, '\0', 4) == FALSE)
		return (FALSE);
	if (mrt_parse_color(&(sphere->albedo), line, 5) == FALSE)
		return (FALSE);
	mrt_parse_add_obj(objs, sphere);
	return (TRUE);
}
