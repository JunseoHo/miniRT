/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vec_scalar_product.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:52:52 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 16:56:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_rt	*mrt_vec_scalar_product(t_vec vec, float scalar)
{
	t_vec	*product;

	product = malloc(sizeof(t_vec));
	if (product == NULL)
		mrt_exit("malloc failed.", errno);
	product->x = vec.x * scalar;
	product->y = vec.y * scalar;
	product->z = vec.z * scalar;
	return (product);
}
