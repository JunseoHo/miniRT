/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:00:07 by jho               #+#    #+#             */
/*   Updated: 2024/01/15 10:45:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_vec	mrt_vec_normalize(t_vec vec)
{
	t_vec	norm;
	float	magnitude;

	magnitude = mrt_vec_magnitude(vec);
	norm.x = vec.x / magnitude;
	norm.y = vec.y / magnitude;
	norm.z = vec.z / magnitude;
	return (norm);
}
