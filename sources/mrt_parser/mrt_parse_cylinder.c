/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:55:33 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 15:30:40 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_obj	*init_cylinder(void)
{
	t_obj	*cylinder;

	cylinder = malloc(sizeof(t_obj));
	if (cylinder == NULL)
		ft_except("Malloc failed.", errno);
	cylinder->type = CY;
	cylinder->next = NULL;
	return (cylinder);
}

t_bool	mrt_parse_cylinder(t_obj **objs, char *line)
{
	t_obj	*cylinder;

	cylinder = init_cylinder();
	if (mrt_parse_vector(&(cylinder->origin), line, 1) == FALSE)
		return (free_obj(cylinder));
	if (mrt_parse_vector(&(cylinder->axis), line, 2) == FALSE)
		return (free_obj(cylinder));
	cylinder->axis = vec_norm(cylinder->axis);
	if (mrt_parse_double(&(cylinder->radius), line, '\0', 3) == FALSE)
		return (free_obj(cylinder));
	cylinder->radius /= 2;
	if (mrt_parse_double(&(cylinder->height), line, '\0', 4) == FALSE)
		return (free_obj(cylinder));
	if (mrt_parse_color(&(cylinder->albedo), line, 5) == FALSE)
		return (free_obj(cylinder));
	mrt_parse_add_obj(objs, cylinder);
	return (TRUE);
}
