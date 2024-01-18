/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 15:25:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "vector.h"

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
	t_obj_type	type;
	t_vec		position;
	t_vec		axis;
	double		diameter;
	double		height;
	int			color;
}	t_obj;

typedef struct s_mrt
{
	t_amb	amb;
	t_cam	cam;
	t_light	light;
	t_obj	*objs;
}	t_mrt;

void	mrt_except(char *message, int exit_code);
bool	mrt_load(t_mrt *mrt, int argc, char **argv);
size_t	mrt_strlen(char *s);
bool	mrt_verify_extension(char *filename);

#endif