/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:39:41 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:04:36 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static	bool	check_count_amb_and_cam_and_lit(t_mrt *mrt)
{
	if (mrt->amb.count_amb != 1 || mrt->cam.count_cam != 1 || mrt->lit.count_lit == 0)
		return (false);
	else
		return (true);
}

t_mrt	*mrt_init(int argc, char **argv)
{
	t_mrt	*mrt;

	mrt = malloc(sizeof(t_mrt));
	if (mrt == NULL)
		ft_except("Malloc failed.", errno);
	mrt->objs = NULL;
	mrt->amb.count_amb = 0;
	mrt->cam.count_cam = 0;
	mrt->lit.count_lit = 0;
	if (mrt_file_parse(mrt, argc, argv) == false)
		return (NULL);
	if (verify_value_range(mrt) == false)
		return (NULL);
	if (check_count_amb_and_cam_and_lit(mrt) == false)
		return (NULL);
	/* Not implemented. */
	/*
	 *	This section is for test only.
	 */
	// mrt->amb.ratio = 0.2;
	// mrt->amb.color = mrt_color(255, 255, 255);
	// mrt->cam.eye = vec(0, 0, 0);
	// mrt->cam.at = vec(0, 0, -1);
	// mrt->cam.up = vec(0, 1, 0);
	// mrt->cam.fov = 90;
	mrt->cam.edge_len = tan((mrt->cam.fov / 2) * (M_PI / 180)) * FOCAL_LEN * 2;
	mrt->cam.row_vec = vec_cross(mrt->cam.at, mrt->cam.up);
	mrt->cam.row_vec = vec_scale(vec_norm(mrt->cam.row_vec), mrt->cam.edge_len);
	mrt->cam.col_vec = vec_cross(mrt->cam.at, mrt->cam.row_vec);
	mrt->cam.col_vec = vec_scale(vec_norm(mrt->cam.col_vec), -mrt->cam.edge_len);
	mrt->cam.leftbottom = vec_add(mrt->cam.eye,
			vec_scale(vec_norm(mrt->cam.at), FOCAL_LEN));
	mrt->cam.leftbottom = vec_sub(mrt->cam.leftbottom,
			vec_scale(mrt->cam.row_vec, 0.5));
	mrt->cam.leftbottom = vec_sub(mrt->cam.leftbottom,
			vec_scale(mrt->cam.col_vec, 0.5));
	// mrt->lit.origin = vec(-40, 40, 0);
	// mrt->lit.bright = 0.8;
	// mrt->lit.color = mrt_color(255, 255, 255);
	// mrt_add_obj(mrt, mrt_cylinder(vec(0, 0, -20.6), vec(0, 1, 0), 14.2, 21.42));
	// mrt_add_obj(mrt, mrt_sphere(vec(2, 0, -5.6), 1.6));
	// mrt->objs->albedo = mrt_color(0, 255, 255);
	// mrt_add_obj(mrt, mrt_sphere(vec(7, 0, -20.6), 12.6));
	// mrt_add_obj(mrt, mrt_sphere(vec(0, 0, -50.6), 12.6));
	// mrt->objs->next->next->albedo = mrt_color(0, 0, 255);
	// mrt_add_obj(mrt, mrt_plane(vec(0, -10, 0), vec(0, 1, 0)));
	// mrt->objs->next->next->next->albedo = mrt_color(60, 179, 113);
	// if you modify this section, you gay. sugo.
	/*
	 *	This section is for test only.
	 */
	return (mrt);
}