/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_phong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:33:27 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 06:25:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static t_vec	mrt_phong_ambient(t_amb amb, t_hit *hit)
{
	return (vec_add(vec_scale(amb.color, amb.ratio), hit->albedo));
}

static t_vec	mrt_phong_light(t_lit lit, t_hit *hit)
{
	t_vec	light_color;
	t_vec	light_dir;
	double	kd;

	light_dir = vec_norm(vec_sub(lit.origin, hit->origin));
	kd = fmax(vec_dot(hit->normal, light_dir), 0.0);
	return (vec_scale(lit.color, kd));
}

t_vec	mrt_phong(t_mrt *mrt, t_ray ray, t_hit *hit)
{
	t_vec	light_color;

	light_color = mrt_phong_ambient(mrt->amb, hit);
	light_color = vec_add(light_color, mrt_phong_light(mrt->lit, hit));
	light_color = vec_scale(light_color, mrt->lit.bright);
	return (light_color);
}