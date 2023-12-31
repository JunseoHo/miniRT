/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:02:57 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 10:50:40 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

static char	*mrt_result_malloc(char *str, char c, char **result, int idx)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	result[idx] = (char *)malloc(sizeof(char) * (len + 1));
	if (result[idx] == NULL)
		mrt_exit("malloc failed.", errno);
	mrt_strlcpy(result[idx], str, len + 1);
	return (result[idx]);
}

static char	**mrt_result_double_malloc(char *str, char c)
{
	size_t	cnt;
	char	**result;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == NULL)
		mrt_exit("malloc failed.", errno);
	return (result);
}

char	**mrt_split(char *s, char c)
{
	char	*str;
	char	**result;
	int		i;

	str = (char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	result = mrt_result_double_malloc(str, c);
	while (*str)
	{
		if (*str != c)
		{
			if (mrt_result_malloc(str, c, result, i++) == NULL)
				return (NULL);
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
