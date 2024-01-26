/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_amb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:07:45 by jho               #+#    #+#             */
/*   Updated: 2024/01/26 11:53:23 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_amb(t_amb *amb, char *line)
{
	char	*token;
	bool	b_parse_success;

	token = mrt_token(line, 1);
	b_parse_success = mrt_parse_double(&(amb->ratio), token, '\0');
	free(token);
	token = mrt_token(line, 2);
	b_parse_success &= mrt_parse_color(&(amb->color), token);
	free(token);
	return (b_parse_success);
}
