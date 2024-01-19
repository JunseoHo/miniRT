/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:25:44 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 18:03:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_rt_raycast(t_scene *scene, t_mrt mrt)
{
	int		row;
	int		col;
	char	*location;

	row = -1;
	while (++row < WIDTH)
	{
		col = -1;
		while (++col < WIDTH)
		{
			location = scene->addr + (col * scene->len + row * scene->bpp / 8);
			*(unsigned int *)location = ((255 << 16) | (255 << 8) | (255));
			vec_add(mrt.viewport_lefttop, mrt.pixel_horizontal);
		}
		vec_add(mrt.viewport_lefttop, vec_scale(mrt.pixel_horizontal, -WIDTH));
		vec_add(mrt.viewport_lefttop, mrt.pixel_vertical);
	}
}

void	mrt_rt_render(t_scene *scene, t_mrt mrt)
{
	t_vec	up;

	vec_init(&up, 0, 1, 0);
	mrt.viewport_center = mrt_viewport_center(mrt.cam);
	mrt.viewport_horizontal = vec_norm(vec_cross(mrt.cam.at, up));
	mrt.viewport_vertical = vec_norm(vec_cross(mrt.cam.at,
				mrt.viewport_horizontal));
	mrt.viewport_lefttop = vec_sub(mrt.viewport_center,
			vec_scale(mrt.viewport_horizontal, -WIDTH / 2));
	mrt.viewport_lefttop = vec_sub(mrt.viewport_lefttop,
			vec_scale(mrt.viewport_vertical, -WIDTH / 2));
	mrt.pixel_horizontal = vec_norm(mrt.viewport_horizontal);
	mrt.pixel_vertical = vec_norm(mrt.viewport_vertical);
	mrt_rt_raycast(scene, mrt);
	mlx_put_image_to_window(scene->ptr, scene->win, scene->img, 0, 0);
	mlx_loop(scene->ptr);
}
