/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:54:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 13:53:19 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	mrt_parse_cam(t_cam *cam, char *line)
{
	if (cam->b_init == TRUE)
		return (FALSE);
	if (mrt_parse_vector(&(cam->eye), line, 1) == FALSE)
		return (FALSE);
	if (mrt_parse_vector(&(cam->at), line, 2) == FALSE)
		return (FALSE);
	if (mrt_parse_double(&(cam->fov), line, '\0', 3) == FALSE)
		return (FALSE);
	cam->up = vec(0, 1, 0);
	cam->b_init = TRUE;
	return (TRUE);
}
