/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:19:39 by jho               #+#    #+#             */
/*   Updated: 2024/01/15 12:01:05 by jho              ###   ########.fr       */
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
	 // 광선을 구의 중심에서 출발하도록 조정
    ray.x -= geo->pos.x;
    ray.y -= geo->pos.y;
    ray.z -= geo->pos.z;

    // 광선을 100배로 확장
    ray = mrt_vec_scalar_product(ray, 100.0f);

    // 구와의 교차 여부 확인
    float a = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
    float b = 2 * (ray.x * geo->pos.x + ray.y * geo->pos.y + ray.z * geo->pos.z);
    float c = geo->pos.x * geo->pos.x + geo->pos.y * geo->pos.y + geo->pos.z * geo->pos.z - geo->d * geo->d;

    float discriminant = b * b - 4 * a * c;

    return (discriminant >= 0);
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

	mrt_vec_init(&camera_at, rt->cam.ori.x, rt->cam.ori.y, rt->cam.ori.z);
	mrt_vec_init(&camera_up, 0, 1, 0);
	viewport_horizon = mrt_vec_cross_product(camera_at, camera_up);
	viewport_vertical = mrt_vec_cross_product(camera_at, *viewport_horizon);
	ray = mrt_vec_scalar_product(camera_at, FOCAL_DISTANCE);
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
				printf("+");
			else
				printf(".");
			//mrt_vec_print("Ray", ray);
		}
		printf("\n");
		ray = mrt_vec_sum(ray, mrt_vec_scalar_product(mrt_vec_normalize(*viewport_vertical), (-1) * (VIEWPORT_LENGTH)));
	}
	free(viewport_horizon);
	free(viewport_vertical);
}
