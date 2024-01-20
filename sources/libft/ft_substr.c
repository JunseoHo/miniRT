/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:31:53 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:29:19 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_substr(char *s, size_t begin, size_t end)
{
	char	*substr;
	size_t	index;

	substr = malloc(sizeof(char) * (end - begin + 1));
	if (substr == NULL)
		ft_except("Malloc failed.", errno);
	index = 0;
	while (begin < end)
	{
		substr[index] = s[begin];
		++index;
		++begin;
	}
	substr[index] = '\0';
	return (substr);
}
