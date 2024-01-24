/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:39:41 by jho               #+#    #+#             */
/*   Updated: 2024/01/24 10:44:00 by jho              ###   ########.fr       */
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
	mrt->cam.len = tan((mrt->cam.fov / 2) * (M_PI / 180)) * FOCAL_LEN * 2;
	mrt->cam.horizontal = vec_cross(mrt->cam.at, mrt->cam.up);
	mrt->cam.horizontal = vec_scale(vec_norm(mrt->cam.horizontal), mrt->cam.len);
	mrt->cam.vertical = vec_cross(mrt->cam.at, mrt->cam.horizontal);
	mrt->cam.vertical = vec_scale(vec_norm(mrt->cam.vertical), -mrt->cam.len);
	mrt->cam.leftbottom = vec_add(mrt->cam.eye,
			vec_scale(vec_norm(mrt->cam.at), FOCAL_LEN));
	mrt->cam.leftbottom = vec_sub(mrt->cam.leftbottom,
			vec_scale(mrt->cam.horizontal, 0.5));
	mrt->cam.leftbottom = vec_sub(mrt->cam.leftbottom,
			vec_scale(mrt->cam.vertical, 0.5));
	mrt->lit.origin = vec(-40, 0, 50);
	mrt->lit.bright = 0.9;
	mrt->lit.color = mrt_color(255, 255, 255);
	mrt_add_obj(mrt, mrt_sphere(vec(7, 0, -20.6), 12.6));
	mrt_add_obj(mrt, mrt_sphere(vec(-7, 0, -20.6), 12.6));
	mrt->objs->next->albedo = mrt_color(0, 0, 255);
	mrt_add_obj(mrt, mrt_sphere(vec(0, -500, 0), 990));
	mrt->objs->next->next->albedo = mrt_color(60, 179, 113);
	// if you modify this section, you gay. sugo.
	/*
	 *	This section is for test only.
	 */
	return (mrt);
}
