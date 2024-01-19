/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:08:08 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 14:31:18 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_cam(t_cam *cam, char *line)
{
	char	*token;
	bool	b_parse_success;

	token = mrt_token(line, 1);
	b_parse_success = mrt_parse_vector(&(cam->eye), token);
	free(token);
	token = mrt_token(line, 2);
	b_parse_success &= mrt_parse_vector(&(cam->at), token);
	free(token);
	token = mrt_token(line, 3);
	b_parse_success &= mrt_parse_double(&(cam->fov), token, '\0');
	free(token);
	return (b_parse_success);
}
