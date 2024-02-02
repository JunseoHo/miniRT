/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:54:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/02 15:01:09 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	mrt_parse_cam(t_cam *cam, char *line)
{
	char	*token;
	t_bool	b_parse_success;	

	if (cam->b_init == TRUE)
		return (FALSE);
	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(cam->eye), token);
	if (token == NULL)
		return (FALSE);
	free(token);
	token = ft_token(line, 2);
	if (token == NULL)
		return (FALSE);
	b_parse_success &= mrt_parse_vector(&(cam->at), token);
	free(token);
	token = ft_token(line, 3);
	if (token == NULL)
		return (FALSE);
	b_parse_success &= mrt_parse_double(&(cam->fov), token, '\0');
	free(token);
	cam->up = vec(0, 1, 0);
	cam->b_init = TRUE;
	return (b_parse_success);
}
