/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:08:51 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 18:17:11 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_parse_add_obj(t_obj **objs, t_obj *obj)
{
	t_obj	*last;

	if (*objs == NULL)
		*objs = obj;
	else
	{
		last = *objs;
		while (last->next != NULL)
			last = last->next;
		last->next = obj;
	}
}

bool	mrt_parse_sphere(t_obj **objs, char *line)
{
	t_obj	*sphere;
	char	*token;
	bool	b_parse_success;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		mrt_except("Malloc failed.", errno);
	sphere->type = SPHERE;
	sphere->next = NULL;
	token = mrt_token(line, 1);
	b_parse_success = mrt_parse_vector(&(sphere->position), token);
	free(token);
	token = mrt_token(line, 2);
	b_parse_success = mrt_parse_double(&(sphere->diameter), token, '\0');
	free(token);
	token = mrt_token(line, 3);
	b_parse_success = mrt_parse_color(&(sphere->color), token);
	free(token);
	mrt_parse_add_obj(objs, sphere);
	return (true);
}
