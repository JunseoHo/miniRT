/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:54:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/27 14:15:40 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_cam(t_cam *cam, char *line)
{
	char	*token;
	bool	b_parse_success;	

	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(cam->eye), token);
	free(token);
	token = ft_token(line, 2);
	b_parse_success &= mrt_parse_vector(&(cam->at), token);
	free(token);
	token = ft_token(line, 3);
	b_parse_success &= mrt_parse_double(&(cam->fov), token, '\0');
	free(token);
	cam->up = vec(0, 1, 0);
	cam->count_cam++;
	return (b_parse_success);
}
