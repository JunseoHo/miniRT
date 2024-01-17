/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:22:57 by jho               #+#    #+#             */
/*   Updated: 2024/01/17 11:41:30 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# define FOCAL_DISTANCE 10.0f
# define VIEWPORT_WIDTH 1000

typedef struct s_axis
{
	float	x;
	float	y;
	float	z;
}	t_axis;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_amb
{
	float	rat;
	t_color	c;
	bool	b_init;
}	t_amb;

typedef struct s_cam
{
	t_axis	pos;
	t_axis	ori;
	float	fov;
	bool	b_init;
}	t_cam;

typedef struct s_lit
{
	t_axis	pos;
	float	br;
	t_color	c;
	bool	b_init;
}	t_lit;

typedef enum e_geo_type
{
	SP,
	PL,
	CY
}	t_geo_type;

typedef struct s_geo
{
	t_geo_type		type;
	t_axis			pos;
	t_axis			ori;
	float			d;
	float			h;
	t_color			c;
	struct s_geo	*next;
}	t_geo;

typedef struct s_rt
{
	t_amb	amb;
	t_cam	cam;
	t_lit	lit;
	t_geo	*geo;
	float	dist;
	int		buffer[1000][1000];

}	t_rt;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

// mrt_main
void	mrt_print(t_rt rt);

// mrt_geo
void	mrt_geo_add_last(t_geo **list, t_geo *geo);
t_geo	*mrt_geo_malloc(t_geo_type type);

// mrt_init
bool	mrt_init_amb(t_amb *amb, char **tokens);
bool	mrt_init_axis(t_axis *axis, char *s);
bool	mrt_init_cam(t_cam *cam, char **tokens);
bool	mrt_init_color(t_color *c, char *s);
bool	mrt_init_cy(t_geo **geo_list, char **tokens);
bool	mrt_init_float(float *result, char *s);
bool	mrt_init_lit(t_lit *lit, char **tokens);
bool	mrt_init_pl(t_geo **geo_list, char **tokens);
bool	mrt_init_rt(t_rt *rt, int fd);
bool	mrt_init_sp(t_geo **geo_list, char **tokens);
bool	mrt_init(t_rt *rt, int argc, char **argv);
// mrt_rt
void	mrt_rt_show(t_rt *rt);
void	mrt_rt(t_rt *rt);

// mrt_util
void	mrt_exit(char *message, int exit_status);
char	**mrt_split(char *s, char c);
int		mrt_strcmp(char *s1, char *s2);
size_t	mrt_strlcpy(char *dst, char *src, size_t dstsize);
int		mrt_strlen(char *s);
bool	mrt_verify_float_range(float f, float min, float max);

t_vec	*mrt_vec_cross_product(t_vec u, t_vec v);
float	mrt_vec_dot_product(t_vec u, t_vec v);
void	mrt_vec_init(t_vec *vec, float x, float y, float z);
float	mrt_vec_magnitude(t_vec vec);
t_vec	mrt_vec_normalize(t_vec vec);
void	mrt_vec_print(char *name, t_vec vec);
t_vec	mrt_vec_scalar_product(t_vec vec, float scalar);
t_vec	*mrt_vec_sub(t_vec u, t_vec v);
t_vec	mrt_vec_sum(t_vec u, t_vec v);
#endif
