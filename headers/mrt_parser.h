/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:09:53 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:13:29 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_PARSER_H
# define MRT_PARSER_H
# include "libft.h"
# include "vector.h"

typedef enum e_obj_type
{
	SP = 0,
	PL = 1,
	CY = 2
}	t_obj_type;

typedef struct s_amb
{
	t_bool	b_init;
	double	ratio;
	t_vec	color;
}	t_amb;

typedef struct s_cam
{
	t_bool	b_init;
	t_vec	eye;
	t_vec	at;
	t_vec	up;
	double	edge_len;
	t_vec	row_vec;
	t_vec	col_vec;
	t_vec	leftbottom;
	double	fov;
}	t_cam;

typedef struct s_lit
{
	t_bool			b_init;
	t_vec			origin;
	double			brightness;
	t_vec			color;
	struct s_lit	*next;
}	t_lit;

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
	t_lit	*lit;
	t_obj	*objs;
}	t_mrt;

t_bool	mrt_file_parse(t_mrt *mrt, int argc, char **argv);
t_bool	mrt_parse_line(t_mrt *mrt, char *line);
t_bool	mrt_parse_amb(t_amb *amb, char *line);
t_bool	mrt_parse_double(double *d, char *token, char end);
t_bool	verify_integer_or_decimal(char **num, char end);
t_bool	mrt_parse_color(t_vec *color, char *token);
t_bool	mrt_parse_cam(t_cam *cam, char *line);
t_bool	mrt_parse_vector(t_vec *vec, char *token);
t_bool	mrt_parse_light(t_lit *lit, char *line);
void	mrt_parse_add_obj(t_obj **objs, t_obj *obj);
t_bool	mrt_parse_sphere(t_obj **objs, char *line);
t_bool	mrt_parse_plane(t_obj **objs, char *line);
t_bool	mrt_parse_cylinder(t_obj **objs, char *line);
t_bool	verify_value_range(t_mrt *mrt);

#endif