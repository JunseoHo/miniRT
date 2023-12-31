/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:28:40 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:47:10 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_cam(t_cam *cam, char **tokens)
{
	bool	b_stat;

	if (cam->b_init || tokens[4] != NULL)
		return (false);
	b_stat = (mrt_init_axis(&(cam->pos), tokens[1])
			&& mrt_init_axis(&(cam->ori), tokens[2])
			&& mrt_init_float(&(cam->fov), tokens[3]));
	if ((mrt_verify_float_range(cam->ori.x, -1, 1) == false) || (mrt_verify_float_range(cam->ori.y, -1, 1) == false) || (mrt_verify_float_range(cam->ori.z, -1, 1) == false) || (mrt_verify_float_range(cam->fov, 0, 180) == false))
		return (false);
	cam->b_init = true;
	return (b_stat);
}
