/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify_integer_or_decimal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:24:23 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/25 15:14:20 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	verify_integer_or_decimal(char *num)
{
	size_t		i;
	size_t		num_len;
	int			decimal_flag;

	i = 0;
	num_len = ft_strlen(num);
	decimal_flag = 0;
	if (num[0] == '+' || num[0] == '-')
		i++;
	while (i < num_len)
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
