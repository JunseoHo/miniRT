/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_print_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:59:48 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:12:03 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_print_amb(t_amb *amb)
{
	if (amb == NULL)
		return ;
	printf("[Amb]\n");
	printf("ratio : %f\n", amb->rat);
	printf("color_r : %d\n", amb->c->r);
	printf("color_g : %d\n", amb->c->g);
	printf("color_b : %d\n", amb->c->b);
}

void	mrt_print_cam(t_cam *cam)
{
	if (cam == NULL)
		return ;
	printf("[Cam]\n");
	printf("Position : %f, %f, %f\n", cam->pos->x, cam->pos->y, cam->pos->z);
	printf("Orientation : %f, %f, %f\n", cam->ori->x, cam->ori->y, cam->ori->z);
	printf("FOV : %f\n", cam->fov);
}

void	mrt_print_lit(t_lit *lit)
{
	if (lit == NULL)
		return ;
	printf("[Lit]\n");
	printf("Position : %f, %f, %f\n", lit->pos->x, lit->pos->y, lit->pos->z);
	printf("Brightness : %f\n", lit->br);
}

void	mrt_print_rt(t_rt *rt)
{
	mrt_print_amb(rt->amb);
	mrt_print_cam(rt->cam);
	mrt_print_lit(rt->lit);
}
