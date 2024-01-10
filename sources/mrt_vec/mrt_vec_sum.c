/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:49:19 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 16:51:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_vec	*mrt_vec_sum(t_vec u, t_vec v)
{
	t_vec	*sum;

	sum = malloc(sizeof(t_vec));
	if (sum == NULL)
		mrt_exit("malloc failed.", errno);
	sum->x = u.x + v.x;
	sum->y = u.y + v.y;
	sum->z = u.z + v.z;
	return (sum);
}
