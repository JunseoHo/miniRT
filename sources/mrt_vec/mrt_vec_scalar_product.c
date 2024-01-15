/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_scalar_product.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:52:52 by jho               #+#    #+#             */
/*   Updated: 2024/01/15 10:22:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_vec	mrt_vec_scalar_product(t_vec vec, float scalar)
{
	t_vec	product;

	product.x = vec.x * scalar;
	product.y = vec.y * scalar;
	product.z = vec.z * scalar;
	return (product);
}
