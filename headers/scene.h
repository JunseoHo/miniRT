/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:05:51 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:15:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include <mlx.h>
# include <stdlib.h>
# define SCENE_WIDTH 		1000
# define SCENE_HEIGHT 		1000
# define KEY_PRESS_EVENT	2
# define KEY_CLICK_EXIT		17
# define KEY_ESC			53

typedef struct s_scene
{
	void	*ptr;
	void	*win;
	int		bpp;
	int		len;
	void	*img;
	int		endian;
	char	*addr;
	char	*loc;
	int		buffer[SCENE_HEIGHT][SCENE_WIDTH];
}	t_scene;

t_scene	*scene_destroy(t_scene *scene);
t_scene	*scene_init(char *name);
void	scene_show(t_scene *scene);

#endif