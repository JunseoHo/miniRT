/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:22:57 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 18:19:34 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdlib.h>
# include <fcntl.h>

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
}	t_amb;

typedef struct s_cam
{
	t_axis	pos;
	t_axis	ori;
	float	fov;
}	t_cam;

typedef struct s_lit
{
	t_axis	pos;
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
	t_axis			pos;
	t_axis			ori;
	float			d;
	float			h;
	t_color			c;
	struct s_geo	*next;
}	t_geo;

typedef struct s_rt
{
	t_amb	*amb;
	t_cam	*cam;
	t_lit	*lit;
	t_geo	*geo;
}	t_rt;
#endif
