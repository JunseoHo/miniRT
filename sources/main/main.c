/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:19 by jho               #+#    #+#             */
/*   Updated: 2024/02/05 17:45:19 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	parse_test_print(t_mrt *mrt)
{
	t_obj *objs = mrt->objs;
	t_lit *lits = mrt->lits;
	printf("A : [%f] [%f %f %f]\n", mrt->amb.ratio, mrt->amb.color.x, mrt->amb.color.y, mrt->amb.color.z);
	printf("C : [%f %f %f] [%f %f %f] [%f]\n", mrt->cam.eye.x, mrt->cam.eye.y, mrt->cam.eye.z, mrt->cam.at.x, mrt->cam.at.y, mrt->cam.at.z, mrt->cam.fov);
	while (lits)
	{
		printf("L : [%f %f %f] [%f] [%f %f %f]\n", lits->origin.x, lits->origin.y, lits->origin.z, lits->brightness, lits->color.x, lits->color.y, lits->color.z);	
		lits = lits->next;
	}
	while (objs)
	{
		if (objs->type == SP)
			printf("sp : [%f %f %f] [%f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->radius, objs->albedo.x, objs->albedo.y, objs->albedo.z);
		else if (mrt->objs->type == PL)
			printf("pl : [%f %f %f] [%f %f %f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->axis.x, objs->axis.y, objs->axis.z, objs->albedo.x, objs->albedo.y, objs->albedo.z);
		else if (mrt->objs->type == CY)
			printf("cy : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->axis.x, objs->axis.y, objs->axis.z, objs->radius, objs->height, objs->albedo.x, objs->albedo.y, objs->albedo.z);	
		else if (mrt->objs->type == CN)
			printf("cn : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->axis.x, objs->axis.y, objs->axis.z, objs->radius, objs->height, objs->albedo.x, objs->albedo.y, objs->albedo.z);	
		objs = objs->next;
	}
	exit(1);
}

void	leaks(void)
{
	system("leaks miniRT");
}

int	main(int argc, char **argv)
{
	t_mrt	*mrt;
	t_scene	*scene;

	mrt = mrt_init(argc, argv);
	if (mrt == NULL)
		ft_except("Error", 1);
	scene = scene_init("miniRT");
	mrt_raytrace(mrt, scene);
	scene_show(scene);
	mrt_destroy(mrt);
	scene_destroy(scene);
	return (0);
}
