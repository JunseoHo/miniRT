/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:00:07 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 17:04:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_vec	*mrt_vec_normalize(t_vec vec)
{
	t_vec	*norm;
	float	magnitude;

	norm = malloc(sizeof(t_vec));
	if (norm == NULL)
		mrt_exit("malloc failed.", errno);
	magnitude = mrt_vec_magnitude(vec);
	norm->x = vec.x / magnitude;
	norm->y = vec.y / magnitude;
	norm->z = vec.z / magnitude;
	return (norm);
}
