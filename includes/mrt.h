/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:22:57 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 15:38:50 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_amb
{
	float	rat;
	int		c;
}	t_amb;

typedef struct s_cam
{
	float	px;
	float	py;
	float	pz;
	float	ox;
	float	oy;
	float	oz;
	float	fov;
}	t_cam;

typedef struct s_lit
{
	float	px;
	float	py;
	float	pz;
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
	float			px;
	float			py;
	float			pz;
	float			ox;
	float			oy;
	float			oz;
	float			d;
	float			h;
	int				c;
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
