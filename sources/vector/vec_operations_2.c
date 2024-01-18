/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:27:51 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 14:36:17 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

t_vec	vec_sub(t_vec u, t_vec v)
{
	t_vec	w;

	vec_init(&w, u.x - v.x, u.y - v.y, u.z - v.z);
	return (w);
}

t_vec	vec_scale(t_vec u, double k)
{
	t_vec	w;

	vec_init(&w, u.x * k, u.y * k, u.z * k);
	return (w);
}
