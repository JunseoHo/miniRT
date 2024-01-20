/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 00:22:59 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include "scene.h"
# include "vector.h"
# define DEFAULT_COLOR 0xFF0000

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

typedef struct s_lit
{
	t_vec	origin;
	double	bright;
	int		color;
}	t_lit;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type		type;
	t_vec			origin;
	t_vec			axis;
	double			radius;
	double			height;
	int				color;
	struct s_obj	*next;
}	t_obj;

typedef struct s_mrt
{
	t_amb	amb;
	t_cam	cam;
	t_lit	lit;
	t_obj	*objs;
}	t_mrt;

void	mrt_add_obj(t_mrt *mrt, t_obj *obj);
int		mrt_color(int r, int g, int b);
t_mrt	*mrt_destroy(t_mrt *mrt);
t_mrt	*mrt_init(int argc, char **argv);
void	mrt_raytrace(t_mrt *mrt, t_scene *scene);
t_obj	*mrt_sphere(t_vec center, double diameter);

#endif