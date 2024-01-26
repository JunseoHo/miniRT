/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/26 14:23:47 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
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
	t_vec	eye;	//view point
	t_vec	at;		//3d norm ori_vector
	t_vec	up;		// 0 1 0 default
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
	double			radius;		//반지름으로 수정됨
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

//parse
t_mrt	*mrt_init(int argc, char **argv);
bool	mrt_file_parse(t_mrt *mrt, int argc, char **argv);
bool	mrt_parse_line(t_mrt *mrt, char *line);
bool	mrt_parse_amb(t_amb *amb, char *line);
bool	mrt_parse_double(double *d, char *token, char end);
bool	verify_integer_or_decimal(char *num, char end);
bool	mrt_parse_color(t_vec *color, char *token);
bool	mrt_parse_cam(t_cam *cam, char *line);
bool	mrt_parse_vector(t_vec *vec, char *token);
bool	mrt_parse_light(t_lit *lit, char *line);
void	mrt_parse_add_obj(t_obj **objs, t_obj *obj);
bool	mrt_parse_sphere(t_obj **objs, char *line);


#endif