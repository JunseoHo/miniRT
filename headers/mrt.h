/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 05:53:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include "scene.h"
# include "vector.h"
# define FOCAL_LEN 1.0
# define T_MIN 1e-6
# define T_MAX INFINITY

typedef struct s_amb
{
	double	ratio;
	t_vec	color;
}	t_amb;

typedef struct s_cam
{
	t_vec	eye;
	t_vec	at;
	t_vec	up;
	double	len;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	leftbottom;
	double	fov;
}	t_cam;

typedef struct s_lit
{
	t_vec	origin;
	double	bright;
	t_vec	color;
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
	t_vec			albedo;
	struct s_obj	*next;
}	t_obj;

typedef struct s_mrt
{
	t_amb	amb;
	t_cam	cam;
	t_lit	lit;
	t_obj	*objs;
}	t_mrt;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;

typedef struct s_hit
{
	t_vec	origin;
	t_vec	normal;
	double	t;
	bool	b_front;
	t_vec	albedo;
}	t_hit;

void	mrt_add_obj(t_mrt *mrt, t_obj *obj);
t_vec	mrt_color(int r, int g, int b);
t_mrt	*mrt_destroy(t_mrt *mrt);
bool	mrt_hit_sphere(t_obj *sphere, t_ray ray, t_hit *hit);
bool	mrt_hit(t_obj *obj, t_ray ray, t_hit *hit);
t_mrt	*mrt_init(int argc, char **argv);
t_vec	mrt_phong(t_mrt *mrt, t_ray ray, t_hit *hit);
t_vec	mrt_ray_at(t_ray ray, double t);
t_ray	mrt_ray(t_vec origin, t_vec dir);
t_vec	mrt_raycast(t_mrt *mrt, t_ray ray);
void	mrt_raytrace(t_mrt *mrt, t_scene *scene);
t_obj	*mrt_sphere(t_vec center, double diameter);

#endif