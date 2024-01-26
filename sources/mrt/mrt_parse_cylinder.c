/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:55:33 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/26 17:59:42 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_cylinder(t_obj **objs, char *line)
{
	t_obj	*sphere;
	char	*token;
	bool	b_parse_success;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		ft_except("Malloc failed.", errno);
	sphere->type = CYLINDER;
	sphere->next = NULL;
	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(sphere->origin), token);
	free(token);
	token = ft_token(line, 2);
	b_parse_success &= mrt_parse_vector(&(sphere->axis), token);
	free(token);
	token = ft_token(line, 3);
	b_parse_success &= mrt_parse_double(&(sphere->radius), token, '\0');
	if (b_parse_success)
		sphere->radius /= 2;	//diameter -> radius
	free(token);
	token = ft_token(line, 4);
	b_parse_success &= mrt_parse_double(&(sphere->height), token, '\0');
	free(token);
	token = ft_token(line, 5);
	b_parse_success &= mrt_parse_color(&(sphere->albedo), token);
	free(token);
	mrt_parse_add_obj(objs, sphere);
	return (true);
}
