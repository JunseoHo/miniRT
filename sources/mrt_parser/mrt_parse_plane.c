/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:24:21 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 14:00:58 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_obj	*init_plane(void)
{
	t_obj	*plane;

	plane = malloc(sizeof(t_obj));
	if (plane == NULL)
		ft_except("Malloc failed.", errno);
	plane->type = PL;
	plane->next = NULL;
	return (plane);
}

t_bool	mrt_parse_plane(t_obj **objs, char *line)
{
	t_obj	*plane;

	plane = init_plane();
	if (mrt_parse_vector(&(plane->origin), line, 1) == FALSE)
		return (FALSE);
	if (mrt_parse_vector(&(plane->axis), line, 2) == FALSE)
		return (FALSE);
	plane->axis = vec_norm(plane->axis);
	if (mrt_parse_color(&(plane->albedo), line, 3) == FALSE)
		return (FALSE);
	mrt_parse_add_obj(objs, plane);
	return (TRUE);
}
