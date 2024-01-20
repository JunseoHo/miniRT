/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 23:54:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include "scene.h"
# include "vector.h"

typedef struct s_amb
{
	double	ratio;
	int		color;
}	t_amb;

typedef struct s_cam
{
	t_vec	eye;
	t_vec	at;
	t_vec	up;
	double	fov;
}	t_cam;

typedef struct s_light
{
	t_vec	position;
	double	brightness;
	int		color;
}	t_light;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type		type;
	t_vec			position;
	t_vec			axis;
	double			diameter;
	double			height;
	int				color;
	struct s_obj	*next;
}	t_obj;

typedef struct s_mrt
{
	t_amb	amb;
	t_cam	cam;
	t_light	light;
	t_obj	*objs;
	t_vec	viewport_center;
	t_vec	viewport_horizontal;
	t_vec	viewport_vertical;
	double	viewport_width;
	t_vec	pixel_horizontal;
	t_vec	pixel_vertical;
	t_vec	viewport_lefttop_dir;
}	t_mrt;

t_mrt	*mrt_destroy(t_mrt *mrt);
t_mrt	*mrt_init(int argc, char **argv);
void	mrt_raytrace(t_mrt *mrt, t_scene *scene);

#endif