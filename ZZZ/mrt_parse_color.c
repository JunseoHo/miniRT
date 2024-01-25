/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:09:23 by jho               #+#    #+#             */
/*   Updated: 2024/01/25 14:49:39 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static bool	mrt_parse_primary_color(int *color, char *token, int *index)
{
	int	primary_color;

	primary_color = 0;
	while (token[*index] >= '0' && token[*index] <= '9')
	{
		primary_color = (primary_color * 10) + (token[(*index)++] - '0');
		if (primary_color < 0 || primary_color > 255)
			return (false);
	}
	*color <<= 8;
	*color |= primary_color;
	return (true);
} 

bool	mrt_parse_color(int *color, char *token)
{
	int		index;

	*color = 0;
	index = 0;
	if (!mrt_parse_primary_color(color, token, &index))
		return (false);
	if (token[index++] != ',')
		return (false);
	if (!mrt_parse_primary_color(color, token, &index))
		return (false);
	if (token[index++] != ',')
		return (false);
	if (!mrt_parse_primary_color(color, token, &index))
		return (false);
	return (true);
}
