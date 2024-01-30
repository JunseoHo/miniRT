/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:53:15 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/27 13:57:14 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_line(t_mrt *mrt, char *line)
{
	char	*token;
	bool	b_parse_success;
	size_t	token_len;

	token = ft_token(line, 0);
	if (token == NULL)
		return (false);
	token_len = ft_strlen(token);
	b_parse_success = false;
	if (token[0] == 'A')
		b_parse_success = mrt_parse_amb(&(mrt->amb), line);
	else if (token[0] == 'C')
		b_parse_success = mrt_parse_cam(&(mrt->cam), line);
	else if (token[0] == 'L')
		b_parse_success = mrt_parse_light(&(mrt->lit), line);
	else if (token_len > 1 && token[0] == 's' && token[1] == 'p')
		b_parse_success = mrt_parse_sphere(&(mrt->objs), line);
	else if (token_len > 1 && token[0] == 'p' && token[1] == 'l')
		b_parse_success = mrt_parse_plane(&(mrt->objs), line);
	else if (token_len > 1 && token[0] == 'c' && token[1] == 'y')
		b_parse_success = mrt_parse_cylinder(&(mrt->objs), line);
	free(token);
	return (b_parse_success);
}
