/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:58:35 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 15:22:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static void	mrt_print_objs(t_obj *objs)
{
	while (objs != NULL)
	{
		if (objs->type == SPHERE)
		{
			printf("[Sphere]\n");
			printf("%-10s: %f, %f, %f\n", "Position", objs->position.x,
				objs->position.y,
				objs->position.z);
			printf("%-10s: %f\n", "Diameter", objs->diameter);
			printf("%-10s: %d, %d, %d\n", "Color", (objs->color >> 16),
		(objs->color >> 8) & 255, (objs->color) & 255);
		}
		objs = objs->next;
	}
}

void	mrt_print(t_mrt mrt)
{
	printf("[Ambient Lightning]\n");
	printf("%-10s: %f\n", "Ratio", mrt.amb.ratio);
	printf("%-10s: %d, %d, %d\n", "Color", (mrt.amb.color >> 16),
		(mrt.amb.color >> 8) & 255, (mrt.amb.color) & 255);
	printf("[Camera]\n");
	printf("%-10s: %f, %f, %f\n", "Position", mrt.cam.eye.x,
		mrt.cam.eye.y,
		mrt.cam.eye.z);
	printf("%-10s: %f, %f, %f\n", "Direction", mrt.cam.at.x,
		mrt.cam.at.y,
		mrt.cam.at.z);
	printf("%-10s: %f\n", "FOV", mrt.cam.fov);
	printf("[Light]\n");
	printf("%-10s: %f, %f, %f\n", "Position", mrt.light.position.x,
		mrt.light.position.y,
		mrt.light.position.z);
	printf("%-10s: %f\n", "Brightness", mrt.light.brightness);
	printf("%-10s: %d, %d, %d\n", "Color", (mrt.light.color >> 16),
		(mrt.light.color >> 8) & 255, (mrt.light.color) & 255);
	mrt_print_objs(mrt.objs);
}
