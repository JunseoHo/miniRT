/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:25:44 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:53:40 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

int	mrt_rt_raycast(t_vec ray_dir, t_vec ray_org, t_obj *objs)
{
	t_vec	obj_org;
	double	coef[3];
	t_vec	ray_norm;	
	double	discriminant;
	double	t;
	int		color[3];

	obj_org = vec_sub(objs->position, ray_org);
	coef[0] = vec_dot(ray_dir, ray_dir);
	coef[1] = 2 * vec_dot(obj_org, ray_dir);
	coef[2] = vec_dot(obj_org, obj_org) - objs->diameter * objs->diameter;
	discriminant = coef[1] * coef[1] - 4 * coef[0] * coef[2];
	if (discriminant < 0)
		return (0);
	t = (-coef[1] - sqrt(discriminant)) / (2.0 * coef[0]);
	ray_norm = vec_norm(vec_sub(vec_add(ray_org, vec_scale(ray_dir, t)), obj_org));
	color[0] = ((ray_norm.x + 1) * 255) / 2;
	color[1] = ((ray_norm.y + 1) * 255) / 2;
	color[2] = ((ray_norm.z + 1) * 255) / 2;
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

void	mrt_rt_raycast_viewport(t_scene *scene, t_mrt mrt)
{
	int		row;
	int		col;
	char	*location;

	row = -1;
	while (++row < SCENE_WIDTH)
	{
		col = -1;
		while (++col < SCENE_WIDTH)
		{
			location = scene->addr + (col * scene->len + row * scene->bpp / 8);
			*(unsigned int *)location = mrt_rt_raycast(mrt.viewport_lefttop_dir,
					mrt.cam.eye, mrt.objs);
			mrt.viewport_lefttop_dir = vec_add(mrt.viewport_lefttop_dir,
					mrt.pixel_horizontal);
		}
		mrt.viewport_lefttop_dir = vec_add(mrt.viewport_lefttop_dir,
				vec_scale(mrt.pixel_horizontal, -SCENE_WIDTH));
		mrt.viewport_lefttop_dir = vec_add(mrt.viewport_lefttop_dir,
				mrt.pixel_vertical);
	}
}

void	mrt_rt_render(t_scene *scene, t_mrt mrt)
{
	t_vec	cam_up;

	vec_init(&cam_up, 0, 1, 0);
	mrt.viewport_width = 2 * FOCAL_LEN * tan((mrt.cam.fov / 2) * (M_PI / 180));
	mrt.viewport_center = (vec_add(mrt.cam.eye,
				vec_scale(vec_norm(mrt.cam.at), FOCAL_LEN)));
	mrt.viewport_horizontal = vec_norm(vec_cross(mrt.cam.at, cam_up));
	mrt.viewport_vertical = vec_norm(vec_cross(mrt.cam.at,
				mrt.viewport_horizontal));
	mrt.viewport_lefttop_dir = vec_sub(mrt.viewport_center,
			vec_scale(mrt.viewport_horizontal, mrt.viewport_width / 2));
	mrt.viewport_lefttop_dir = vec_sub(mrt.viewport_lefttop_dir,
			vec_scale(mrt.viewport_vertical, mrt.viewport_width / 2));
	mrt.viewport_lefttop_dir = vec_sub(mrt.viewport_lefttop_dir, mrt.cam.eye);
	mrt.pixel_horizontal = vec_scale(vec_norm(mrt.viewport_horizontal),
			mrt.viewport_width / SCENE_WIDTH);
	mrt.pixel_vertical = vec_scale(vec_norm(mrt.viewport_vertical),
			mrt.viewport_width / SCENE_WIDTH);
	mrt_rt_raycast_viewport(scene, mrt);
	mlx_put_image_to_window(scene->ptr, scene->win, scene->img, 0, 0);
	mlx_loop(scene->ptr);
}
