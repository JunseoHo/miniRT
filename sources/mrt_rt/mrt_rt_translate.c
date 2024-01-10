/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:04:32 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 10:12:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_translate_lit(t_lit *lit, int *diff)
{
	lit->pos.x += diff[0];
	lit->pos.y += diff[1];
	lit->pos.z += diff[2];
}

void	mrt_translate_geo(t_geo *geo, int *diff)
{
	while (geo != NULL)
	{
		geo->pos.x += diff[0];
		geo->pos.y += diff[1];
		geo->pos.z += diff[2];
		geo = geo->next;
	}
}

void	mrt_translate(t_rt *rt)
{
	int	diff[3];

	diff[0] = 0 - ((rt->cam).pos.x);
	diff[1] = 0 - ((rt->cam).pos.y);
	diff[2] = 0 - ((rt->cam).pos.z);
	mrt_translate_lit(&(rt->lit), diff);
	mrt_translate_geo(rt->geo, diff);
}
