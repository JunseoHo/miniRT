/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:19:57 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 17:13:10 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/scene.h"

static	int	close_win(t_scene *scene)
{
	mlx_destroy_window(scene->ptr, scene->win);
	free(scene);
	exit(0);
}

static int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
		close_win(scene);
	return (0);
}

void	scene_show(t_scene *scene)
{
	mlx_put_image_to_window(scene->ptr, scene->win, scene->img, 0, 0);
	mlx_hook(scene->win, KEY_PRESS_EVENT, 0, &key_hook, scene);
	mlx_hook(scene->win, KEY_CLICK_EXIT, 0, &close_win, scene);
	mlx_loop(scene->ptr);
}
