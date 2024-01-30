/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:47:45 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 18:41:31 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static int	mrt_to_color(t_vec vec)
{
	int	color;

	if (vec.x > 1.0)
		vec.x = 1.0;
	if (vec.y > 1.0)
		vec.y = 1.0;
	if (vec.z > 1.0)
		vec.z = 1.0;
	color = (int)(vec.x * 255);
	color <<= 8;
	color |= (int)(vec.y * 255);
	color <<= 8;
	color |= (int)(vec.z * 255);
	return (color);
}

void	mrt_raytrace(t_mrt *mrt, t_scene *scene)
{
	int		idx[2];
	t_vec	dir;
	t_ray	ray;
	int		img_offset[2];

	idx[0] = -1;
	while (++idx[0] < SCENE_HEIGHT)
	{
		idx[1] = -1;
		while (++idx[1] < SCENE_WIDTH)
		{
			dir = mrt->cam.leftbottom;
			dir = vec_add(dir, vec_scale(mrt->cam.row_vec,
						(double)idx[1] / (SCENE_WIDTH - 1)));
			dir = vec_add(dir, vec_scale(mrt->cam.col_vec,
						(double)idx[0] / (SCENE_HEIGHT - 1)));
			ray = mrt_ray(mrt->cam.eye, dir);
			img_offset[0] = (SCENE_HEIGHT - idx[0] - 1) * scene->len;
			img_offset[1] = idx[1] * (scene->bpp / 8);
			scene->loc = scene->addr + img_offset[0] + img_offset[1];
			*(unsigned int *)scene->loc = mrt_to_color(mrt_raycast(mrt, ray));
		}
	}
}
