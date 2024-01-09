/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:37:43 by jho               #+#    #+#             */
/*   Updated: 2024/01/09 09:40:04 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_vec	*mrt_rt_dir(t_cam cam, int x, int y)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (vec == NULL)
		mrt_exit("malloc failed.", errno);
	
}
