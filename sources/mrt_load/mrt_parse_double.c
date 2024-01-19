/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:10:27 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 14:30:44 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_double(double *d, char *token, char end)
{
	int		sign;
	double	decimal;

	if (token == NULL)
		return (false);
	*d = 0;
	sign = 1;
	if (*token == '-')
	{
		sign = -1;
		++token;
	}
	while (*token >= '0' && *token <= '9')
		*d = (*d * 10) + (*(token++) - '0');
	if (*token == '.')
	{
		decimal = 0.1;
		while (*(++token) >= '0' && *token <= '9')
		{
			*d += (*(token) - '0') * decimal;
			decimal *= 0.1;
		}
	}
	*d *= sign;
	return (*token == end);
}
