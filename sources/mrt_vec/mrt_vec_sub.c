/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:52:03 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 16:55:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_vec	*mrt_vec_sub(t_vec u, t_vec v)
{
	t_vec	*sub;

	sub = malloc(sizeof(t_vec));
	if (sub == NULL)
		mrt_exit("malloc failed.", errno);
	sub->x = u.x - v.x;
	sub->y = u.y - v.y;
	sub->z = u.z - v.z;
	return (sub);
}