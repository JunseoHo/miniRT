/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:20:37 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 14:36:23 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	vec_add(t_vec u, t_vec v)
{
	t_vec	w;

	vec_init(&w, u.x + v.x, u.y + v.y, u.z + v.z);
	return (w);
}

t_vec	vec_cross(t_vec u, t_vec v)
{
	t_vec	w;

	vec_init(&w,
		u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x);
	return (w);
}

double	vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double	vec_len(t_vec u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}

t_vec	vec_norm(t_vec u)
{
	double	len;
	t_vec	w;

	len = vec_len(u);
	vec_init(&w, u.x / len, u.y / len, u.z / len);
	return (w);
}
