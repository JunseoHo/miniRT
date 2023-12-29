/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_axis_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:05:31 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 21:07:18 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_axis	*mrt_axis_malloc(void)
{
	t_axis	*axis;

	axis = malloc(sizeof(t_axis));
	if (axis == NULL)
		return (axis);
	axis->x = 0;
	axis->y = 0;
	axis->z = 0;
	return (axis);
}
