/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:42 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/26 17:50:45 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_light(t_lit *lit, char *line)
{
	char	*token;
	bool	b_parse_success;

	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(lit->origin), token);
	free(token);
	token = ft_token(line, 2);
	b_parse_success &= mrt_parse_double(&(lit->bright), token, '\0');
	free(token);
	token = ft_token(line, 3);
	b_parse_success &= mrt_parse_color(&(lit->color), token);
	free(token);
	lit->count_lit++;
	return (true);
}
