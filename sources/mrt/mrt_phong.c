/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_phong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:33:27 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 12:02:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static t_vec	mrt_phong_ambient(t_amb amb)
{
	return (vec_scale(amb.color, amb.ratio));
}

static t_vec	mrt_phong_object(t_vec light_color, t_hit *hit)
{
	return (vec(light_color.x * hit->albedo.x,
			light_color.y * hit->albedo.y,
			light_color.z * hit->albedo.z));
}

static t_vec	mrt_phong_light(t_vec light_color, t_lit lit, t_hit *hit)
{
	t_vec	light_dir;
	double	kd;

	light_dir = vec_norm(vec_sub(lit.origin, hit->origin));
	kd = vec_dot(hit->normal, light_dir);
	if (kd < 0.0)
		kd = 0.0;
	return (vec_scale(lit.color, kd));
}

t_vec	mrt_phong(t_mrt *mrt, t_ray ray, t_hit *hit)
{
	t_vec	light_color;

	light_color = mrt_phong_ambient(mrt->amb);
	light_color = mrt_phong_object(light_color, hit);
	light_color = mrt_phong_light(light_color, mrt->lit, hit);
	return (light_color);
}