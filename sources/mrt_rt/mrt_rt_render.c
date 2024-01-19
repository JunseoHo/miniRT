/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:25:44 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 20:32:48 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

int	mrt_rt_raycast(t_vec ray, t_vec eye, t_obj *objs)
{
	t_vec	ray_norm;	
	t_vec	origin_center;
	double	a;
	double	b;
	double	c;

	ray_norm = vec_norm(ray);
	origin_center = vec_sub(objs->position, eye);
	a = vec_dot(ray_norm, ray_norm);
	b = 2 * vec_dot(origin_center, ray_norm);
	c = vec_dot(origin_center, origin_center) - objs->diameter * objs->diameter;
	if (b * b - 4 * a * c > 0)
		return ((255 << 16) | (255 << 8) | (255));
	return (0);
}

void	mrt_rt_raycast_viewport(t_scene *scene, t_mrt mrt)
{
	int		row;
	int		col;
	char	*location;

	row = -1;
	while (++row < SCENE_W)
	{
		col = -1;
		while (++col < SCENE_W)
		{
			location = scene->addr + (col * scene->len + row * scene->bpp / 8);
			*(unsigned int *)location = mrt_rt_raycast(mrt.viewport_lefttop,
					mrt.cam.eye, mrt.objs);
			mrt.viewport_lefttop = vec_add(mrt.viewport_lefttop,
					mrt.pixel_horizontal);
		}
		mrt.viewport_lefttop = vec_add(mrt.viewport_lefttop,
				vec_scale(mrt.pixel_horizontal, -SCENE_W));
		mrt.viewport_lefttop = vec_add(mrt.viewport_lefttop,
				mrt.pixel_vertical);
	}
}

void	mrt_rt_render(t_scene *scene, t_mrt mrt)
{
	t_vec	up;

	vec_init(&up, 0, 1, 0);
	mrt.viewport_width = mrt_viewport_width(mrt.cam.fov);
	mrt.viewport_center = mrt_viewport_center(mrt.cam);
	mrt.viewport_horizontal = vec_norm(vec_cross(mrt.cam.at, up));
	mrt.viewport_vertical = vec_norm(vec_cross(mrt.cam.at,
				mrt.viewport_horizontal));
	mrt.viewport_lefttop = vec_sub(mrt.viewport_center,
			vec_scale(mrt.viewport_horizontal, mrt.viewport_width / 2));
	mrt.viewport_lefttop = vec_sub(mrt.viewport_lefttop,
			vec_scale(mrt.viewport_vertical, mrt.viewport_width / 2));
	mrt.pixel_horizontal = vec_scale(vec_norm(mrt.viewport_horizontal),
			mrt.viewport_width / SCENE_W);
	mrt.pixel_vertical = vec_scale(vec_norm(mrt.viewport_vertical),
			mrt.viewport_width / SCENE_W);
	mrt_rt_raycast_viewport(scene, mrt);
	mlx_put_image_to_window(scene->ptr, scene->win, scene->img, 0, 0);
	mlx_loop(scene->ptr);
}
