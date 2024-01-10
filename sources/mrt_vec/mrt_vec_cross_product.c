/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_cross_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:57:54 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 17:07:10 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_rt	*mrt_vec_cross_product(t_vec u, t_vec v)
{
	t_vec	*cross;

	cross = malloc(sizeof(t_vec));
	if (cross == NULL)
		mrt_exit("malloc failed.", errno);
	cross->x = u.y * v.z - u.z * v.y;
	cross->y = u.z * v.x - u.x * v.z;
	cross->z = u.x * v.y - u.y * v.x;
	return (cross);
}
