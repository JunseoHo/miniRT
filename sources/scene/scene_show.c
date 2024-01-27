/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:19:57 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:21:01 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/scene.h"

void	scene_show(t_scene *scene)
{
	mlx_put_image_to_window(scene->ptr, scene->win, scene->img, 0, 0);
	mlx_loop(scene->ptr);
}
