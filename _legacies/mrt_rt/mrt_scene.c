/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:06:14 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:53:40 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_scene_init(t_scene *scene)
{
	size_t	index;

	scene->ptr = mlx_init();
	scene->win = mlx_new_window(scene->ptr, SCENE_WIDTH, SCENE_WIDTH, "miniRT");
	scene->img = mlx_new_image(scene->ptr, SCENE_WIDTH, SCENE_WIDTH);
	scene->addr = mlx_get_data_addr(scene->img,
			&(scene->bpp), &(scene->len), &(scene->endian));
	scene->buffer = malloc(sizeof(int *) * SCENE_WIDTH);
	index = 0;
	while (index < SCENE_WIDTH)
	{
		(scene->buffer)[index] = malloc(sizeof(int) * SCENE_WIDTH);
		++index;
	}
}
