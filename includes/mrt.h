/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:22:57 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:44:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"

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
	t_color	*c;
}	t_amb;

typedef struct s_cam
{
	t_axis	*pos;
	t_axis	*ori;
	float	fov;
}	t_cam;

typedef struct s_lit
{
	t_axis	*pos;
	float	br;
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
	t_axis			*pos;
	t_axis			*ori;
	float			d;
	float			h;
	t_color			*c;
	struct s_geo	*next;
}	t_geo;

typedef struct s_rt
{
	t_amb	*amb;
	t_cam	*cam;
	t_lit	*lit;
	t_geo	*geo;
}	t_rt;

// mrt_parse
int		mrt_parse_amb(t_rt *rt, char **tokens);
t_axis	*mrt_parse_axis(char *s);
int		mrt_parse_cam(t_rt *rt, char **tokens);
t_color	*mrt_parse_color(char *s);
int		mrt_parse_cy(t_rt *rt, char **tokens);
t_rt	*mrt_parse_file(int fd);
int		mrt_parse_lit(t_rt *rt, char **tokens);
int		mrt_parse_pl(t_rt *rt, char **tokens);
int		mrt_parse_sp(t_rt *rt, char **tokens);
t_rt	*mrt_parse(int argc, char *argv[]);
int		mrt_verify_file_name(char *name);
// mrt_rt
t_axis	*mrt_axis_free(t_axis *axis);
t_axis	*mrt_axis_malloc(void);
t_color	*mrt_color_free(t_color *c);
t_color	*mrt_color_malloc(void);
t_geo	*mrt_geo_malloc(t_geo_type type);
void	mrt_print_rt(t_rt *rt);
void	mrt_rt_add_geo(t_rt *rt, t_geo *geo);
t_rt	*mrt_rt_free(t_rt *rt);
t_rt	*mrt_rt_malloc(void);
// mrt_util
float	mrt_atof(char *s);
int		mrt_count_tokens(char **tokens);
void	mrt_exit(char *message);
void	mrt_free_tokens(char **tokens);
int		mrt_isdigit(int c);
char	*mrt_skip_numeric(char *s);
char	**mrt_split(char *s, char c);
int		mrt_strcmp(char *s1, char *s2);
size_t	mrt_strlcpy(char *dst, char *src, size_t dstsize);
int		mrt_strlen(char *s);
#endif
