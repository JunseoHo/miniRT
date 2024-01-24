/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:54:03 by jho               #+#    #+#             */
/*   Updated: 2024/01/24 10:43:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"
#include <stdio.h>

int	vec_color(t_vec u)
{
	int	color;

	if (u.x > 1.0)
		u.x = 1.0;
	if (u.y > 1.0)
		u.y = 1.0;
	if (u.z > 1.0)
		u.z = 1.0;
	color = (int)(u.x * 255);
	color <<= 8;
	color |= (int)(u.y * 255);
	color <<= 8;
	color |= (int)(u.z * 255);
	return (color);
}