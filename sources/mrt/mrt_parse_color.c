/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:27:40 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/27 14:13:49 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static	bool	atod(double *color, int *index, char *token)
{
	while (token[*index] >= '0' && token[*index] <= '9')
	{
		*color = (*color * 10) + (token[(*index)++] - '0');
		if (*color < 0 || *color > 255)
			return (false);
	}
	return (true);
}

bool	mrt_parse_color(t_vec *color, char *token)
{
	int		index;

	index = 0;
	color->x = 0;
	color->y = 0;
	color->z = 0;
	if (atod(&(color->x), &index, token) == false)
		return (false);
	if (token[index++] != ',')
		return (false);
	if (atod(&(color->y), &index, token) == false)
		return (false);
	if (token[index++] != ',')
		return (false);
	if (atod(&(color->z), &index, token) == false)
		return (false);
	color->x /= 255;
	color->y /= 255;
	color->z /= 255;
	return (true);
}
