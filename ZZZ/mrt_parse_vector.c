/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:24:07 by jho               #+#    #+#             */
/*   Updated: 2024/01/25 16:36:30 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static size_t	mrt_parse_vector_shift_index(char *token, size_t index)
{
	if (token[index] == '-')
		++index;
	while (token[index] >= '0' && token[index] <= '9')
		++index;
	if (token[index] == '.')
	{
		++index;
		while (token[index] >= '0' && token[index] <= '9')
			++index;
	}
	return (index);
}

bool	mrt_parse_vector(t_vec *vec, char *token)
{
	size_t	index;

	if (!mrt_parse_double(&(vec->x), token, ','))
		return (false);
	index = mrt_parse_vector_shift_index(token, 0);
	if (!mrt_parse_double(&(vec->y), token + index + 1, ','))
		return (false);
	index = mrt_parse_vector_shift_index(token, index + 1);
	if (!mrt_parse_double(&(vec->z), token + index + 1, '\0'))
		return (false);
	return (true);
}
