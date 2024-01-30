/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_last_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:56:38 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/30 16:01:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*p;
	char	*result;

	p = (char *)s;
	result = 0;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(p + i) == (char)c)
			result = p + i;
		i++;
	}
	return (result);
}
