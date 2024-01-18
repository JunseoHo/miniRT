/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:59 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 14:36:42 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	vec_add(t_vec u, t_vec v);
t_vec	vec_cross(t_vec u, t_vec v);
double	vec_dot(t_vec u, t_vec v);
void	vec_init(t_vec *vec, double x, double y, double z);
double	vec_len(t_vec u);
t_vec	vec_norm(t_vec u);
t_vec	vec_scale(t_vec u, double k);
t_vec	vec_sub(t_vec u, t_vec v);
#endif