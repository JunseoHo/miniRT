/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:27:17 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:36:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_print_float(char *label, float value)
{
	printf("%s -> %f\n", label, value);
}

void	mrt_print_axis(char *label, t_axis axis)
{
	printf("%s -> x: %f, y: %f, z: %f\n", label, axis.x, axis.y, axis.z);
}

void	mrt_print_color(t_color c)
{
	printf("Color -> r: %d, g: %d, b: %d\n", c.r, c.g, c.b);
}

void	mrt_print(t_rt rt)
{
	t_geo	*geo;

	printf("[Amb]\n");
	mrt_print_float("Ratio", rt.amb.rat);
	mrt_print_color(rt.amb.c);
	printf("[Cam]\n");
	mrt_print_axis("Position", rt.cam.pos);
	mrt_print_axis("Orientation", rt.cam.ori);
	mrt_print_float("FOV", rt.cam.fov);
	printf("[Lit]\n");
	mrt_print_axis("Position", rt.lit.pos);
	mrt_print_float("Brightness", rt.lit.br);
	geo = rt.geo;
	while (geo != NULL)
	{
		if (geo->type == SP)
		{
			printf("[Sp]\n");
			mrt_print_axis("Position", geo->pos);
			mrt_print_float("Diameter", geo->d);
			mrt_print_color(geo->c);
		}
		else if (geo->type == PL)
		{
			printf("[Pl]\n");
			mrt_print_axis("Position", geo->pos);
			mrt_print_axis("Orientation", geo->ori);
			mrt_print_color(geo->c);
		}
		else if (geo->type == CY)
		{
			printf("[Cy]\n");
			mrt_print_axis("Position", geo->pos);
			mrt_print_axis("Orientation", geo->ori);
			mrt_print_float("Diameter", geo->d);
			mrt_print_float("Height", geo->h);
			mrt_print_color(geo->c);
		}
		geo = geo->next;
	}
}
