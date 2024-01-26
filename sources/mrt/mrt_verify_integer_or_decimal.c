/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify_integer_or_decimal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:24:23 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/26 13:14:37 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	verify_integer_or_decimal(char *num, char end)
{
	size_t		i;
	int			decimal_flag;

	i = 0;
	decimal_flag = 0;
	if (num[0] == '+' || num[0] == '-')
		i++;
	while (num[i] && num[i] != end)
	{
		if (ft_isdigit(num[i]) == 0)
		{
			if (decimal_flag == 0 && num[i] == '.')
				decimal_flag = 1;
			else
				return (false);
		}
		i++;
	}
	return (true);
}
