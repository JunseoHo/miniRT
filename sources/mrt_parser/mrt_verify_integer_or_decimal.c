/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify_integer_or_decimal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:24:23 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 14:55:28 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	void	make_adjust_decimal_to_six_point(char **num, size_t	num_len)
{
	int		i;
	int		decimal_point;
	char	*adjust_num;

	i = 0;
	while (i < num_len)
	{
		if ((*num)[i] == '.')
			break ;
		i++;
	}
	decimal_point = i;
	while (i < num_len)
	{
		if (i > decimal_point + 6)
			break ;
		i++;
	}
	adjust_num = ft_substr(*num, 0, i);
	ft_strlcpy(*num, adjust_num, i + 1);
	free(adjust_num);
}

t_bool	verify_integer_or_decimal(char **num, char end)
{
	size_t		i;
	int			decimal_flag;

	i = 0;
	decimal_flag = 0;
	if ((*num)[0] == '+' || (*num)[0] == '-')
		i++;
	if (!ft_isdigit((*num)[i]))
		return (FALSE);
	while ((*num)[i] && (*num)[i] != end)
	{
		if (ft_isdigit((*num)[i]) == 0)
		{
			if (decimal_flag == 0 && (*num)[i] == '.')
				decimal_flag = 1;
			else
				return (FALSE);
		}
		i++;
	}
	if (decimal_flag == 1)
		make_adjust_decimal_to_six_point(num, ft_strlen(*num));
	return (TRUE);
}
