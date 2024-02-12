/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:55:33 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/12 19:09:13 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_obj	*init_cone(void)
{
	t_obj	*cone;

	cone = malloc(sizeof(t_obj));
	if (cone == NULL)
		ft_except("Malloc failed.", errno);
	cone->type = CN;
	cone->next = NULL;
	return (cone);
}

t_bool	mrt_parse_cone(t_obj **objs, char *line)
{
	t_obj	*cone;

	cone = init_cone();
	if (mrt_parse_vector(&(cone->origin), line, 1) == FALSE)
		return (free_obj(cone));
	if (mrt_parse_vector(&(cone->axis), line, 2) == FALSE)
		return (free_obj(cone));
	cone->axis = vec_norm(cone->axis);
	if (mrt_parse_double(&(cone->radius), line, '\0', 3) == FALSE)
		return (free_obj(cone));
	cone->radius /= 2;
	if (mrt_parse_double(&(cone->height), line, '\0', 4) == FALSE)
		return (free_obj(cone));
	if (mrt_parse_color(&(cone->albedo), line, 5) == FALSE)
		return (free_obj(cone));
	if (cone->radius <= 0 || cone->height <= 0)
		return (free_obj(cone));
	mrt_parse_add_obj(objs, cone);
	return (TRUE);
}
