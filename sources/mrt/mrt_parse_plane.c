/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:24:21 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/26 14:25:55 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_plane(t_obj **objs, char *line)
{
	t_obj	*plane;
	char	*token;
	bool	b_parse_success;

	plane = malloc(sizeof(t_obj));
	if (plane == NULL)
		ft_except("Malloc failed.", errno);
	plane->type = SPHERE;
	plane->next = NULL;
	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(plane->axis), token);
	free(token);
	token = ft_token(line, 2);
	b_parse_success = mrt_parse_double(&(plane->radius), token, '\0');
	free(token);
	token = ft_token(line, 3);
	b_parse_success = mrt_parse_color(&(plane->albedo), token);
	free(token);
	mrt_parse_add_obj(objs, plane);
	return (true);
}
