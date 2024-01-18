/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:11:41 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 17:03:28 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static bool	mrt_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == 'r' || c == '\0');
}

static bool	mrt_is_endl(char c)
{
	return (c == '\0' || c == '\n');
}

char	*mrt_token(char *line, size_t target_index)
{
	size_t	begin;
	size_t	end;
	size_t	index;

	begin = 0;
	end = 0;
	index = 0;
	while (1)
	{
		while (!mrt_is_whitespace(line[end]))
			++end;
		if (begin == end)
			return (NULL);
		if (index == target_index)
			return (mrt_substr(line, begin, end));
		if (mrt_is_endl(line[end]))
			return (NULL);
		begin = (end++) + 1;
		++index;
	}
}
