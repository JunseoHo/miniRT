/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:39:41 by jho               #+#    #+#             */
/*   Updated: 2024/02/02 15:55:30 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_bool	check_count_amb_and_cam_and_lit(t_mrt *mrt)
{
	if (!(mrt->amb.b_init) || !(mrt->cam.b_init) || mrt->lits == NULL)
		return (FALSE);
	else
		return (TRUE);
}

static	void	init_viewport(t_mrt *mrt)
{
	mrt->cam.edge_len = tan((mrt->cam.fov / 2) * (M_PI / 180)) * FOCAL_LEN * 2;
	mrt->cam.row_vec = vec_cross(mrt->cam.at, mrt->cam.up);
	mrt->cam.row_vec = vec_scale(vec_norm(mrt->cam.row_vec), mrt->cam.edge_len);
	mrt->cam.col_vec = vec_cross(mrt->cam.at, mrt->cam.row_vec);
	mrt->cam.col_vec = vec_scale(vec_norm(mrt->cam.col_vec), \
	-mrt->cam.edge_len);
	mrt->cam.leftbottom = vec_add(mrt->cam.eye,
			vec_scale(vec_norm(mrt->cam.at), FOCAL_LEN));
	mrt->cam.leftbottom = vec_sub(mrt->cam.leftbottom,
			vec_scale(mrt->cam.row_vec, 0.5));
	mrt->cam.leftbottom = vec_sub(mrt->cam.leftbottom,
			vec_scale(mrt->cam.col_vec, 0.5));
}

t_mrt	*mrt_init(int argc, char **argv)
{
	t_mrt	*mrt;

	mrt = malloc(sizeof(t_mrt));
	if (mrt == NULL)
		ft_except("Malloc failed.", errno);
	mrt->objs = NULL;
	mrt->amb.b_init = FALSE;
	mrt->cam.b_init = FALSE;
	mrt->lits = NULL;
	if (mrt_file_parse(mrt, argc, argv) == FALSE)
		return (NULL);
	if (verify_value_range(mrt) == FALSE)
		return (NULL);
	if (check_count_amb_and_cam_and_lit(mrt) == FALSE)
		return (NULL);
	init_viewport(mrt);
	return (mrt);
}
