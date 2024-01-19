/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 20:29:43 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "vector.h"
# define SCENE_W 1000
# define FOCAL_LEN 1.0

typedef struct s_amb
{
	double	ratio;
	int		color;
}	t_amb;

typedef struct s_cam
{
	t_vec	eye;
	t_vec	at;
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
	t_vec	viewport_lefttop;
}	t_mrt;

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
	int		**buffer;
}	t_scene;

void	mrt_scene_init(t_scene *scene);
void	mrt_except(char *message, int exit_code);
bool	mrt_load(t_mrt *mrt, int argc, char **argv);
bool	mrt_parse_amb(t_amb *amb, char *line);
bool	mrt_parse_cam(t_cam *cam, char *line);
bool	mrt_parse_color(int *color, char *token);
bool	mrt_parse_cylinder(t_obj **obj, char *line);
bool	mrt_parse_double(double *d, char *token, char end);
bool	mrt_parse_light(t_light *light, char *line);
bool	mrt_parse_plane(t_obj **obj, char *line);
bool	mrt_parse_sphere(t_obj **obj, char *line);
bool	mrt_parse_vector(t_vec *vec, char *token);
bool	mrt_parse(t_mrt *mrt, char *line);
void	mrt_print(t_mrt mrt);
void	mrt_rt_render(t_scene *scene, t_mrt mrt);
void	mrt_rt(t_mrt mrt);
int		mrt_strcmp(char *s1, char *s2);
size_t	mrt_strlen(char *s);
char	*mrt_substr(char *s, size_t begin, size_t end);
char	*mrt_token(char *line, size_t target_index);
bool	mrt_verify_extension(char *filename);
t_vec	mrt_viewport_center(t_cam cam);
double	mrt_viewport_focal_len(double w, double fov);
double	mrt_viewport_width(double fov);

#endif