/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:38:49 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 21:19:33 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_axis	*mrt_parse_axis_content(float *a, char *s)
{
	int		sign;
	float	dec;

	sign = 1;
	dec = 0.1;
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	while (mrt_isdigit(*s))
		*a = (*a) * 10 + (*(s++) - '0');
	if (*s == '.' && mrt_isdigit(*(s + 1)))
	{
		++s;
		while (mrt_isdigit(*s))
		{
			*a += dec * (*(s++) - '0');
			dec *= 0.1;
		}	
	}
	if (*a > -1000 || *a < 1000)
		return (NULL);
	return (s);
}

t_axis	*mrt_parse_axis(char *s)
{
	t_axis	*axis;

	axis = mrt_axis_malloc();
	if (axis == NULL)
		return (NULL);
	s = mrt_parse_axis_content(&(axis->x), s);
	if (s == NULL || *s != ',')
		return (mrt_free_axis(axis));
	++s;
	s = mrt_parse_axis_content(&(axis->y), s);
	if (s == NULL || *s != ',')
		return (mrt_free_axis(axis));
	++s;
	s = mrt_parse_axis_content(&(axis->z), s);
	if (s == NULL || *s != '\0')
		return (mrt_free_axis(axis));
	return (axis);
}