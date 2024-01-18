/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:31:53 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 16:57:44 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

char	*mrt_substr(char *s, size_t begin, size_t end)
{
	char	*substr;
	size_t	index;

	substr = malloc(sizeof(char) * (end - begin + 1));
	if (substr == NULL)
		mrt_except("Malloc failed.", errno);
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
