/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:13:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "mrt_parser.h"
# include "scene.h"
# define FOCAL_LEN 10.0
# define T_MIN 1e-6
# define T_MAX INFINITY

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;

typedef struct s_hit
{
	t_vec	origin;
	t_vec	normal;
	double	len;
	t_bool	b_front;
	t_vec	albedo;
}	t_hit;

void	mrt_add_obj(t_mrt *mrt, t_obj *obj);
t_vec	mrt_color(int r, int g, int b);
t_obj	*mrt_cylinder(t_vec center, t_vec axis, double diameter, double height);
t_mrt	*mrt_destroy(t_mrt *mrt);
t_bool	mrt_hit_cylinder(t_obj *sphere, t_ray ray, t_hit *hit);
t_bool	mrt_hit_plane(t_obj *sphere, t_ray ray, t_hit *hit);
t_bool	mrt_hit_sphere(t_obj *sphere, t_ray ray, t_hit *hit);
t_bool	mrt_hit(t_obj *obj, t_ray ray, t_hit *hit);
t_mrt	*mrt_init(int argc, char **argv);
t_vec	mrt_phong(t_mrt *mrt, t_ray ray, t_hit *hit);
t_obj	*mrt_plane(t_vec center, t_vec normal);
t_vec	mrt_ray_at(t_ray ray, double t);
t_ray	mrt_ray(t_vec origin, t_vec dir);
t_vec	mrt_raycast(t_mrt *mrt, t_ray ray);
void	mrt_raytrace(t_mrt *mrt, t_scene *scene);
t_obj	*mrt_sphere(t_vec center, double diameter);

#endif
