/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:19:39 by jho               #+#    #+#             */
/*   Updated: 2024/01/16 12:17:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_rt_translate_geo(t_rt *rt)
{
	t_geo	*geo;

	geo = rt->geo;
	while (geo != NULL)
	{
		geo->pos.x -= rt->cam.pos.x;
		geo->pos.y -= rt->cam.pos.y;
		geo->pos.z -= rt->cam.pos.z;
		geo = geo->next;
	}
}

bool	mrt_rt_verify(t_geo *geo, t_vec ray)
{
	t_vec	pos;
	t_vec	origin;
	t_vec	*oc;
	t_vec	dir;

	mrt_vec_init(&pos, geo->pos.x, geo->pos.y, geo->pos.z);
	mrt_vec_init(&origin, 0, 0, 0);
	dir = mrt_vec_normalize(ray);
	oc = mrt_vec_sub(origin, pos);
	float a = mrt_vec_dot_product(dir, dir);
	float b = 2 * mrt_vec_dot_product(*oc, dir);
	float c = mrt_vec_dot_product(*oc, *oc) - geo->d * geo->d;

	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

void	mrt_rt(t_rt *rt)
{
	t_vec	camera_at;
	t_vec	camera_up;
	t_vec	*viewport_horizon;
	t_vec	*viewport_vertical;
	t_vec	ray;
	int		index_horizontal;
	int		index_vertical;
	float	focal_distance;

	mrt_vec_init(&camera_at, rt->cam.ori.x, rt->cam.ori.y, rt->cam.ori.z);
	mrt_vec_init(&camera_up, 0, 1, 0);
	rt->cam.fov = 90;
	viewport_horizon = mrt_vec_cross_product(camera_at, camera_up);
	viewport_vertical = mrt_vec_cross_product(camera_at, *viewport_horizon);
	focal_distance = (1.0f / tan((M_PI / 180.0f) * (rt->cam.fov / 2))) * (0.5f * VIEWPORT_LENGTH);
	ray = mrt_vec_scalar_product(camera_at, focal_distance);
	ray = mrt_vec_sum(ray, mrt_vec_scalar_product(mrt_vec_normalize(*viewport_horizon), -0.5f * VIEWPORT_LENGTH));
	ray = mrt_vec_sum(ray, mrt_vec_scalar_product(mrt_vec_normalize(*viewport_vertical), -0.5f * VIEWPORT_LENGTH));
	mrt_vec_print("Camera_At", camera_at);
	mrt_vec_print("Horizontal", *viewport_horizon);
	mrt_vec_print("Vertical", *viewport_vertical);
	mrt_vec_print("Ray", ray);
	mrt_rt_translate_geo(rt);
	index_horizontal = -1;
	while (++index_horizontal < VIEWPORT_LENGTH)
	{
		index_vertical = -1;
		ray = mrt_vec_sum(ray, mrt_vec_normalize(*viewport_horizon));
		while (++index_vertical < VIEWPORT_LENGTH)
		{
			ray = mrt_vec_sum(ray, mrt_vec_normalize(*viewport_vertical));
			if (mrt_rt_verify(rt->geo, ray))
			{
				mrt_vec_print("Ray", ray);
				rt->buffer[index_vertical][index_horizontal] = (255 << 16);
			}
			else
				rt->buffer[index_vertical][index_horizontal] = (0);
		}
		ray = mrt_vec_sum(ray, mrt_vec_scalar_product(mrt_vec_normalize(*viewport_vertical), (-1) * (VIEWPORT_LENGTH)));
	}
	free(viewport_horizon);
	free(viewport_vertical);
	mrt_rt_show(rt);
}
