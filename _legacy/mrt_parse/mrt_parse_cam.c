/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:07:22 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 08:46:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_cam(t_rt *rt, char **tokens)
{
	if (rt->cam != NULL)
		return (0);
	rt->cam = malloc(sizeof(t_cam));
	if (rt->cam == NULL)
		mrt_exit("malloc failed.");
	rt->cam->pos = mrt_parse_axis(tokens[1]);
	rt->cam->ori = mrt_parse_axis(tokens[2]);
	rt->cam->fov = mrt_atof(tokens[3]);
	return (1);
}