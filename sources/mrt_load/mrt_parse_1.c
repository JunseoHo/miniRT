/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:59:23 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 17:16:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_amb(t_amb *amb, char *line)
{
	return (true);
}

bool	mrt_parse_cam(t_cam *cam, char *line)
{
	return (true);
}

bool	mrt_parse_light(t_light *light, char *line)
{
	return (true);
}

bool	mrt_parse_sphere(t_obj *obj, char *line)
{
	return (true);
}

bool	mrt_parse(t_mrt *mrt, char *line)
{
	char	*token;
	bool	b_parse_success;

	token = mrt_token(line, 0);
	if (token == NULL)
		return (false);
	b_parse_success = false;
	if (mrt_strcmp(token, "A"))
		b_parse_success = mrt_parse_amb(&(mrt->amb), line);
	else if (mrt_strcmp(token, "C"))
		b_parse_success = mrt_parse_cam(&(mrt->cam), line);
	else if (mrt_strcmp(token, "L"))
		b_parse_success = mrt_parse_light(&(mrt->light), line);
	else if (mrt_strcmp(token, "sp"))
		b_parse_success = mrt_parse_sphere(mrt->objs, line);
	else if (mrt_strcmp(token, "pl"))
		b_parse_success = mrt_parse_plane(mrt->objs, line);
	else if (mrt_strcmp(token, "cy"))
		b_parse_success = mrt_parse_cylinder(mrt->objs, line);
	free(token);
	return (b_parse_success);
}
