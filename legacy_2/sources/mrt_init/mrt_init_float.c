/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:16:34 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 11:47:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_float(float *result, char *s)
{
	float	dec;
	int		sign;

	*result = 0;
	dec = 0.1f;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	while (*s >= '0' && *s < '9')
		*result = (*result) * 10 + (*(s++) - '0');
	if (*s == '.')
	{
		++s;
		while (*s >= '0' && *s < '9')
		{
			*result = (*result) + ((*(s++) - '0') * dec);
			dec *= 0.1f;
			++s;
		}
	}
	*result *= sign;
	return (true);
}
