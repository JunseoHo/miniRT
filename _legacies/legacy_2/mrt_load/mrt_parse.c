/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:59:23 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 18:13:56 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse(t_mrt *mrt, char *line)
{
	char	*token;
	bool	b_parse_success;

	token = mrt_token(line, 0);
	if (token == NULL)
		return (false);
	b_parse_success = false;
	if (mrt_strcmp(token, "A") == 0)
		b_parse_success = mrt_parse_amb(&(mrt->amb), line);
	else if (mrt_strcmp(token, "C") == 0)
		b_parse_success = mrt_parse_cam(&(mrt->cam), line);
	else if (mrt_strcmp(token, "L") == 0)
		b_parse_success = mrt_parse_light(&(mrt->light), line);
	else if (mrt_strcmp(token, "sp") == 0)
		b_parse_success = mrt_parse_sphere(&(mrt->objs), line);
	else if (mrt_strcmp(token, "pl") == 0)
		b_parse_success = mrt_parse_plane(&(mrt->objs), line);
	else if (mrt_strcmp(token, "cy") == 0)
		b_parse_success = mrt_parse_cylinder(&(mrt->objs), line);
	free(token);
	return (b_parse_success);
}
