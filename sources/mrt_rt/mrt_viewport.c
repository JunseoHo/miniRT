/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:15:27 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 16:15:55 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_vec	mrt_viewport_center(t_cam cam)
{
	double	focal_len;

	focal_len = mrt_viewport_focal_len(WIDTH, cam.fov);
	return (vec_add(cam.eye, vec_scale(vec_norm(cam.at), focal_len)));
}

double	mrt_viewport_focal_len(size_t w, double fov)
{
	return ((w / 2) * tan((fov / 2) * (M_PI / 180)));
}
