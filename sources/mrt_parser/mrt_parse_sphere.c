/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:03:39 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/12 19:07:15 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_obj	*init_sphere(void)
{
	t_obj	*sphere;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		ft_except("Malloc failed.", errno);
	sphere->type = SP;
	sphere->next = NULL;
	return (sphere);
}

t_bool	mrt_parse_sphere(t_obj **objs, char *line)
{
	t_obj	*sphere;

	sphere = init_sphere();
	if (mrt_parse_vector(&(sphere->origin), line, 1) == FALSE)
		return (free_obj(sphere));
	if (mrt_parse_double(&(sphere->radius), line, '\0', 2) == FALSE)
		return (free_obj(sphere));
	sphere->radius /= 2;
	if (sphere->radius <= 0)
		return (free_obj(sphere));
	if (mrt_parse_color(&(sphere->albedo), line, 3) == FALSE)
		return (free_obj(sphere));
	mrt_parse_add_obj(objs, sphere);
	return (TRUE);
}
