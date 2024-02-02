/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:19 by jho               #+#    #+#             */
/*   Updated: 2024/02/02 14:15:50 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

int	main(int argc, char **argv)
{
	t_mrt	*mrt;
	t_scene	*scene;

	mrt = mrt_init(argc, argv);
	if (mrt == NULL)
		ft_except("Error", 1);
		printf("A : [%f] [%f %f %f]\n", mrt->amb.ratio, mrt->amb.color.x, mrt->amb.color.y, mrt->amb.color.z);
	printf("C : [%f %f %f] [%f %f %f] [%f]\n", mrt->cam.eye.x, mrt->cam.eye.y, mrt->cam.eye.z, mrt->cam.at.x, mrt->cam.at.y, mrt->cam.at.z, mrt->cam.fov);
	printf("L : [%f %f %f] [%f] [%f %f %f]\n", mrt->lits->origin.x, mrt->lits->origin.y, mrt->lits->origin.z, mrt->lits->brightness, mrt->lits->color.x, mrt->lits->color.y, mrt->lits->color.z);
	exit(1);
	scene = scene_init("miniRT");
	mrt_raytrace(mrt, scene);
	scene_show(scene);
	mrt_destroy(mrt);
	scene_destroy(scene);
	return (0);
}
