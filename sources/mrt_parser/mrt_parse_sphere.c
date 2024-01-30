/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:03:39 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/30 16:05:58 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,255
// cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255

#include "../../headers/mrt.h"

bool	mrt_parse_sphere(t_obj **objs, char *line)
{
	t_obj	*sphere;
	char	*token;
	bool	b_parse_success;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		ft_except("Malloc failed.", errno);
	sphere->type = SP;
	sphere->next = NULL;
	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(sphere->origin), token);
	free(token);
	token = ft_token(line, 2);
	b_parse_success &= mrt_parse_double(&(sphere->radius), token, '\0');
	if (b_parse_success)
		sphere->radius /= 2;	//diameter -> radius
	free(token);
	token = ft_token(line, 3);
	b_parse_success &= mrt_parse_color(&(sphere->albedo), token);
	free(token);
	mrt_parse_add_obj(objs, sphere);
	return (true);
}