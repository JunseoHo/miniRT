/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_amb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:41:48 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/01 16:38:52 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	mrt_parse_amb(t_amb *amb, char *line)
{
	char	*token;
	t_bool	b_parse_success;

	if (amb->b_init == TRUE)
		return (FALSE);
	token = ft_token(line, 1);
	b_parse_success = mrt_parse_double(&(amb->ratio), token, '\0');
	free(token);
	token = ft_token(line, 2);
	b_parse_success &= mrt_parse_color(&(amb->color), token);
	free(token);
	amb->b_init = TRUE;
	return (b_parse_success);
}
