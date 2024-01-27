/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:05:18 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:54:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/scene.h"

t_scene	*scene_init(char *name)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	scene->ptr = mlx_init();
	scene->win = mlx_new_window(scene->ptr, SCENE_WIDTH, SCENE_HEIGHT, name);
	scene->img = mlx_new_image(scene->ptr, SCENE_WIDTH, SCENE_HEIGHT);
	scene->addr = mlx_get_data_addr(scene->img,
			&(scene->bpp), &(scene->len), &(scene->endian));
	return (scene);
}
