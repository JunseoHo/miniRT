/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:32:18 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:58:15 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

static char	*mrt_init_axis_value(float *result, char *s)
{
	float	dec;
	int		sign;

	*result = 0.0f;
	dec = 0.1f;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	while (*s >= '0' && *s <= '9')
		*result = (*result) * 10 + (*(s++) - '0');
	if (*s == '.')
	{
		++s;
		while (*s >= '0' && *s <= '9')
		{
			*result = (*result) + ((*(s++) - '0') * dec);
			dec *= 0.1f;
		}
	}
	*result *= sign;
	return (s);
}

bool	mrt_init_axis(t_axis *axis, char *s)
{
	s = mrt_init_axis_value(&(axis->x), s);
	printf("%s\n", s);
	if (s == NULL || *(s++) != ',')
		return (false);
	s = mrt_init_axis_value(&(axis->y), s);
	if (s == NULL || *(s++) != ',')
		return (false);
	s = mrt_init_axis_value(&(axis->z), s);
	if (s == NULL || (*s != '\0' && *s != '\n'))
		return (false);
	return (true);
}
