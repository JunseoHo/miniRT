/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:19 by jho               #+#    #+#             */
/*   Updated: 2024/02/03 14:14:28 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static	void	parse_test_print(t_mrt *mrt)
{
	printf("A : [%f] [%f %f %f]\n", mrt->amb.ratio, mrt->amb.color.x, mrt->amb.color.y, mrt->amb.color.z);
	printf("C : [%f %f %f] [%f %f %f] [%f]\n", mrt->cam.eye.x, mrt->cam.eye.y, mrt->cam.eye.z, mrt->cam.at.x, mrt->cam.at.y, mrt->cam.at.z, mrt->cam.fov);
	while (mrt->lits)
	{
		printf("L : [%f %f %f] [%f] [%f %f %f]\n", mrt->lits->origin.x, mrt->lits->origin.y, mrt->lits->origin.z, mrt->lits->brightness, mrt->lits->color.x, mrt->lits->color.y, mrt->lits->color.z);	
		mrt->lits = mrt->lits->next;
	}
	while (mrt->objs)
	{
		if (mrt->objs->type == SP)
			printf("sp : [%f %f %f] [%f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->radius, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);
		else if (mrt->objs->type == PL)
			printf("pl : [%f %f %f] [%f %f %f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->axis.x, mrt->objs->axis.y, mrt->objs->axis.z, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);
		else if (mrt->objs->type == CY)
			printf("cy : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->axis.x, mrt->objs->axis.y, mrt->objs->axis.z, mrt->objs->radius, mrt->objs->height, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);	
		else if (mrt->objs->type == CN)
			printf("cn : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", mrt->objs->origin.x, mrt->objs->origin.y, mrt->objs->origin.z, mrt->objs->axis.x, mrt->objs->axis.y, mrt->objs->axis.z, mrt->objs->radius, mrt->objs->height, mrt->objs->albedo.x, mrt->objs->albedo.y, mrt->objs->albedo.z);	
		mrt->objs = mrt->objs->next;
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mrt	*mrt;
	t_scene	*scene;

	mrt = mrt_init(argc, argv);
	if (mrt == NULL)
		ft_except("Error", 1);
	parse_test_print(mrt);
	scene = scene_init("miniRT");
	mrt_raytrace(mrt, scene);
	scene_show(scene);
	mrt_destroy(mrt);
	scene_destroy(scene);
	return (0);
}
