/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:06:21 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 16:15:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	mrt_atof(char *s)
{
	float	result;
	float	decimal;
	int		sign;

	result = 0;
	decimal = 0.1;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	while (*s >= '0' && *s < '9')
		result = result * 10 + (*(s++) - '0');
	if (*s == '.')
	{
		++s;
		while (*s >= '0' && *s < '9')
		{
			result = result + ((*(s++) - '0') * decimal);
			decimal *= 0.1;
			++s;
		}
	}
	return (result);
}
