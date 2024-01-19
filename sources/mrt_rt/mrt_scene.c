/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:06:14 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 16:23:21 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_scene_init(t_scene *scene)
{
	size_t	index;

	scene->ptr = mlx_init();
	scene->win = mlx_new_window(scene->ptr, WIDTH, WIDTH, "miniRT");
	scene->img = mlx_new_image(scene->ptr, WIDTH, WIDTH);
	scene->addr = mlx_get_data_addr(scene->img,
			&(scene->bpp), &(scene->len), &(scene->endian));
	scene->buffer = malloc(sizeof(int *) * WIDTH);
	index = 0;
	while (index < WIDTH)
	{
		(scene->buffer)[index] = malloc(sizeof(int) * WIDTH);
		++index;
	}
}

void	mrt_scene_show(t_scene *scene)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < WIDTH)
	{
		col = 0;
		while (col < WIDTH)
		{
			scene->loc = scene->addr
				+ (col * scene->len + row * scene->bpp / 8);
			*(unsigned int *)scene->loc = scene->buffer[col][row];
			++col;
		}
		++row;
	}
	mlx_put_image_to_window(scene->ptr, scene->win, scene->img, 0, 0);
	mlx_loop(scene->ptr);
}
