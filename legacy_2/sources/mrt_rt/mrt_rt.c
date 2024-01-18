/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:19:39 by jho               #+#    #+#             */
/*   Updated: 2024/01/17 18:19:42 by jho              ###   ########.fr       */
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

t_vec	mrt_vec_subtract(t_vec u, t_vec v)
{
	t_vec	sub;

	mrt_vec_init(&sub, u.x - v.x, u.y - v.y, u.z - v.z);
	return sub;
}

double	mrt_rt_hit_sphere(t_geo *geo, t_vec ray, t_vec origin_to_center)
{
	float a = mrt_vec_dot_product(ray, ray);
	float b = 2.0 * mrt_vec_dot_product(origin_to_center, ray);
	float c = mrt_vec_dot_product(origin_to_center, origin_to_center) - pow(geo->d, 2);
	float discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return -1.0f;
	else
		return (-b - sqrt(discriminant) / (2.0 * a));
}

void	mrt_rt(t_rt *rt)
{
	int aspect_ratio = 1; // This is an ideal ratio, not actual.
	int image_width = 1000;
	int image_height = image_width / aspect_ratio;
	double viewport_height = 2.0;
	double viewport_width = viewport_height * (image_width / image_height);
	t_vec	camera_eye;
	t_vec	viewport_horizontal;
	t_vec	viewport_vertical;
	t_vec	pixel_delta_horizontal;
	t_vec	pixel_delta_vertical;
	t_vec	viewport_upper_left;
	t_vec	focal_length;
	mrt_vec_init(&camera_eye, rt->cam.pos.x, rt->cam.pos.y, rt->cam.pos.z);
	mrt_vec_init(&viewport_horizontal, viewport_width, 0, 0);
	mrt_vec_init(&viewport_vertical, 0, -viewport_height, 0);
	mrt_vec_init(&focal_length, 0, 0, 1);
	pixel_delta_horizontal = viewport_horizontal;
	pixel_delta_vertical = viewport_vertical;
	pixel_delta_horizontal = mrt_vec_scalar_product(pixel_delta_horizontal, 1 / (float)image_width);
	pixel_delta_vertical = mrt_vec_scalar_product(pixel_delta_vertical, 1 / (float)image_height);
	viewport_upper_left = camera_eye;
	viewport_upper_left = mrt_vec_subtract(viewport_upper_left, focal_length);
	viewport_upper_left = mrt_vec_subtract(viewport_upper_left, mrt_vec_scalar_product(viewport_horizontal, 0.5));
	viewport_upper_left = mrt_vec_subtract(viewport_upper_left, mrt_vec_scalar_product(viewport_vertical, 0.5));
	t_vec	pixel_upper_left = viewport_upper_left;
	pixel_upper_left = mrt_vec_sum(pixel_upper_left, mrt_vec_scalar_product(pixel_delta_horizontal, 0.5));
	pixel_upper_left = mrt_vec_sum(pixel_upper_left, mrt_vec_scalar_product(pixel_delta_vertical, 0.5));
	

	int	index_width = 0;
	int	index_height = 0;
	t_vec	pixel_center;
	t_vec	sphere_center;
	mrt_vec_init(&sphere_center, rt->geo->pos.x, rt->geo->pos.y, rt->geo->pos.z);
	while (index_height < image_height)
	{
		index_width = 0;
		while (index_width < image_width)
		{
			pixel_center = pixel_upper_left;
			pixel_center = mrt_vec_sum(pixel_center, mrt_vec_scalar_product(pixel_delta_horizontal,(float) index_width));
			pixel_center = mrt_vec_sum(pixel_center, mrt_vec_scalar_product(pixel_delta_vertical,(float) index_height));
			double discriminant = mrt_rt_hit_sphere(rt->geo, pixel_center, mrt_vec_subtract(camera_eye, sphere_center));
			if (discriminant > 0.0)
			{
				t_vec ray_at = mrt_vec_sum(camera_eye, mrt_vec_scalar_product(pixel_center, discriminant));
				t_vec camera_at;
				mrt_vec_init(&camera_at, 0, 0, -1);
				t_vec N = mrt_vec_normalize(mrt_vec_subtract(ray_at, camera_at));
				int r = (N.x + 1) * 0.5 * 255;
				int g = (N.y + 1) * 0.5 * 255;
				int b = (N.z + 1) * 0.5 * 255;
				rt->buffer[index_height][index_width] = (r << 16) | (g << 8) | b;
			}
			else
			{
				rt->buffer[index_height][index_width] = 0;
			}
			++index_width;
		}
		++index_height;
	}
	mrt_rt_show(rt);
}

/*
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
*/
