/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:19 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:47:10 by jho              ###   ########.fr       */
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
	scene = scene_init("miniRT");
	mrt_raytrace(mrt, scene);
	mrt_destroy(mrt);
	scene_destroy(scene);
	return (0);
}
