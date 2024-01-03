/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_add_geo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:32:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:33:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_rt_add_geo(t_rt *rt, t_geo *geo)
{
	t_geo	*last;

	if (rt->geo == NULL)
		rt->geo = geo;
	else
	{
		last = rt->geo;
		while (last->next != NULL)
			last = last->next;
		last->next = geo;
	}
}
