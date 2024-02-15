/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify_integer_or_decimal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:24:23 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/12 21:11:52 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_bool	adjust_number(char **num, int i)
{
	char	*adjust_num;

	adjust_num = ft_substr(*num, 0, i);
	if (adjust_num == NULL)
		return (FALSE);
	ft_strlcpy(*num, adjust_num, i + 1);
	free(adjust_num);
	return (TRUE);
}

static	t_bool	make_adjust_decimal_to_six_point(char **num, size_t	num_len)
{
	int		i;
	int		decimal_point;

	i = 0;
	while (i < num_len)
	{
		if ((*num)[i] == '.')
		{
			if (ft_isdigit((*num)[i + 1]) == FALSE)
				return (FALSE);
			break ;
		}
		i++;
	}
	if (i > 7)
		return (FALSE);
	decimal_point = i;
	while (i < num_len)
	{
		if (i > decimal_point + 7)
			return (FALSE);
		i++;
	}
	return (adjust_number(num, i));
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
		return (make_adjust_decimal_to_six_point(num, ft_strlen(*num)));
	return (i < 7);
}
