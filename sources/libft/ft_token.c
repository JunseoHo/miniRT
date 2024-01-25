/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:11:41 by jho               #+#    #+#             */
/*   Updated: 2024/01/25 14:25:20 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == 'r' || c == '\0');
}

static bool	ft_is_endl(char c)
{
	return (c == '\0' || c == '\n');
}

char	*ft_token(char *line, size_t target_index)
{
	size_t	begin;
	size_t	end;
	size_t	index;

	begin = 0;
	end = 0;
	index = 0;
	while (1)
	{
		while (ft_is_whitespace(line[begin]))
			++begin;
		end = begin;
		while (!ft_is_whitespace(line[end]))
			++end;
		if (begin == end)
			return (NULL);
		if (index == target_index)
			return (ft_substr(line, begin, end));
		if (ft_is_endl(line[end]))
			return (NULL);
		begin = (end++) + 1;
		++index;
	}
}

// static bool	verify_number(char *num)
// {
// 	int		i;
// 	size_t	num_len;

// 	i = 0;
// 	while (i < num_len)
// 	{
// 		if (ft_isdigit(num[i]) == 0)
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }
