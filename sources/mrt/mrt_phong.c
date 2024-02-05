/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_phong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:33:27 by jho               #+#    #+#             */
/*   Updated: 2024/02/05 18:26:58 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static t_vec	mrt_phong_ambient(t_amb *amb)
{
	return (vec_scale(amb->color, amb->ratio));
}

static t_vec	mrt_phong_diffuse(t_lit *lit, t_ray ray, t_hit *hit)
{
	t_vec	diffuse;
	t_vec	light_dir;
	double	kd;

	light_dir = vec_norm(vec_sub(lit->origin, hit->origin));
	kd = vec_dot(hit->normal, light_dir);
	if (kd < 0)
		kd = 0;
	diffuse = vec_scale(lit->color, kd);
	return (diffuse);
}

static t_vec	mrt_phong_reflect_dir(t_vec u, t_vec v)
{
	return (vec_sub(u, vec_scale(v, vec_dot(u, v) * 2)));
}

static t_vec	mrt_phong_specular(t_lit *lit, t_ray ray, t_hit *hit)
{
	t_vec	light_dir;
	t_vec	eye_dir;
	t_vec	reflect_dir;
	double	spec;

	light_dir = vec_norm(vec_sub(lit->origin, hit->origin));
	eye_dir = vec_norm(vec_scale(ray.dir, -1));
	reflect_dir = mrt_phong_reflect_dir(vec_scale(light_dir, -1), hit->normal);
	spec = pow(fmax(vec_dot(eye_dir, reflect_dir), 0.0), KSN);
	return (vec_scale(vec_scale(lit->color, KS), spec));
}

t_vec	mrt_phong(t_mrt *mrt, t_ray ray, t_hit *hit)
{
	t_vec	light_color;
	t_lit	*lits;

	lits = mrt->lits;
	light_color = vec(0, 0, 0);
	while (lits != NULL)
	{
		light_color = vec_add(light_color, mrt_phong_diffuse(lits, ray, hit));
		light_color = vec_add(light_color, mrt_phong_specular(lits, ray, hit));
		lits = lits->next;
	}
	light_color = vec_add(light_color, mrt_phong_ambient(&(mrt->amb)));
	return (vec(light_color.x * hit->albedo.x,
			light_color.y * hit->albedo.y,
			light_color.z * hit->albedo.z));
}
