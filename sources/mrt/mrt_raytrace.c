/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:47:45 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 04:45:18 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_raytrace(t_mrt *mrt, t_scene *scene)
{
	int		row;
	int		col;
	t_vec	dir;
	t_ray	ray;

	row = -1;
	while (++row < SCENE_HEIGHT)
	{
		col = -1;
		while (++col < SCENE_WIDTH)
		{
			dir = mrt->cam.leftbottom;
			dir = vec_add(dir, vec_scale(mrt->cam.horizontal, (double)col / (SCENE_WIDTH - 1)));
			dir = vec_add(dir, vec_scale(mrt->cam.vertical, (double)row / (SCENE_HEIGHT - 1)));
			ray = mrt_ray(mrt->cam.eye, dir);
			scene->loc = scene->addr + ((SCENE_HEIGHT - row - 1) * scene->len + col * scene->bpp / 8);
			*(unsigned int *)scene->loc = mrt_raycast(mrt, ray);
		}
	}
}
