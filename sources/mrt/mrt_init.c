/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:39:41 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 00:55:00 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_mrt	*mrt_init(int argc, char **argv)
{
	t_mrt	*mrt;

	mrt = malloc(sizeof(t_mrt));
	if (mrt == NULL)
		ft_except("Malloc failed.", errno);
	mrt->objs = NULL;
	/* Not implemented. */
	/*
	 *	This section is for test only.
	 */
	mrt->amb.ratio = 0.2;
	mrt->amb.color = mrt_color(255, 255, 255);
	mrt->cam.eye = vec(0, 0, 0);
	mrt->cam.at = vec(0, 0, -1);
	mrt->cam.up = vec(0, 1, 0);
	mrt->cam.fov = 90;
	mrt->cam.side_len = tan((mrt->cam.fov /  2) / (M_PI / 180));
	mrt->lit.origin = vec(-40, 0, 50);
	mrt->lit.bright = 0.6;
	mrt->lit.color = mrt_color(10, 0, 255);
	mrt_add_obj(mrt, mrt_sphere(vec(15, 0, -20.6), 12.6));
	mrt_add_obj(mrt, mrt_sphere(vec(-15, 15, -20.6), 12.6));
	/*
	 *	This section is for test only.
	 */
	return (mrt);
}
