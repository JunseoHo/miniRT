/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:15:27 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 20:26:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_vec	mrt_viewport_center(t_cam cam)
{
	return (vec_add(cam.eye, vec_scale(vec_norm(cam.at), FOCAL_LEN)));
}

double	mrt_viewport_width(double fov)
{
	return (2 * FOCAL_LEN * tan((fov / 2) * (M_PI / 180)));
}

double	mrt_viewport_focal_len(double w, double fov)
{
	return ((w / 2) * tan((fov / 2) * (M_PI / 180)));
}
