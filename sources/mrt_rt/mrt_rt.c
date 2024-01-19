/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:02:01 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 18:02:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_rt(t_mrt mrt)
{
	t_scene	scene;

	mrt_scene_init(&scene);
	mrt_rt_render(&scene, mrt);
}
