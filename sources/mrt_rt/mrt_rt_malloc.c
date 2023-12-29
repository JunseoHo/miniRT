/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:32:14 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 15:40:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_rt	*mrt_rt_malloc(void)
{
	t_rt	*rt;

	rt = malloc(sizeof(t_rt));
	if (rt == NULL)
		return (NULL);
	rt->amb = NULL;
	rt->cam = NULL;
	rt->lit = NULL;
	rt->geo = NULL;
	return (rt);
}