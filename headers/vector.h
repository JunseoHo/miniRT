/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:59 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 18:41:28 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	vec(double x, double y, double z);
t_vec	vec_add(t_vec u, t_vec v);
t_vec	vec_cross(t_vec u, t_vec v);
double	vec_dot(t_vec u, t_vec v);
double	vec_len(t_vec u);
t_vec	vec_norm(t_vec u);
void	vec_print(t_vec vec);
t_vec	vec_scale(t_vec u, double k);
t_vec	vec_sub(t_vec u, t_vec v);

#endif