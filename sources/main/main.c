/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:19 by jho               #+#    #+#             */
/*   Updated: 2024/01/26 18:16:21 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

int	main(int argc, char **argv)
{
	t_mrt	*mrt;

	mrt = mrt_init(argc, argv);
	if (mrt == NULL)
		ft_except("Error", 1);
	printf("A : [%f] [%f %f %f]\n", mrt->amb.ratio, mrt->amb.color.x, mrt->amb.color.y, mrt->amb.color.z);
	printf("C : [%f %f %f] [%f %f %f] [%f]\n", mrt->cam.eye.x, mrt->cam.eye.y, mrt->cam.eye.z, mrt->cam.at.x, mrt->cam.at.y, mrt->cam.at.z, mrt->cam.fov);
	printf("L : [%f %f %f] [%f] [%f %f %f]\n", mrt->lit.origin.x, mrt->lit.origin.y, mrt->lit.origin.z, mrt->lit.bright, mrt->lit.color.x, mrt->lit.color.y, mrt->lit.color.z);
	printf("sp : [%f %f %f] [%f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->radius, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);
	mrt->objs = mrt->objs->next;
	printf("pl : [%f %f %f] [%f %f %f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->axis.x, mrt->objs->axis.y, mrt->objs->axis.z, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);
	mrt->objs = mrt->objs->next;
	printf("cy : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->axis.x, mrt->objs->axis.y, mrt->objs->axis.z, mrt->objs->radius, mrt->objs->height, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);

	return (0);
}
