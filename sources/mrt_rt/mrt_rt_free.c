/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:34:33 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 15:39:59 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_rt_free_amb(t_amb *amb)
{
	if (amb != NULL)
		free(amb);
}

void	mrt_rt_free_cam(t_cam *cam)
{
	if (cam != NULL)
		free(cam);
}

void	mrt_rt_free_lit(t_lit *lit)
{
	if (lit != NULL)
		free(lit);
}

void	mrt_rt_free_geo(t_geo *geo)
{
	t_geo	*next;

	if (geo == NULL)
		return ;
	next = geo->next;
	free(geo);
	mrt_rt_free_geo(next);
}

t_rt	*mrt_rt_free(t_rt *rt)
{
	if (rt == NULL)
		return (NULL);
	mrt_rt_free_amb(rt->amb);
	mrt_rt_free_cam(rt->cam);
	mrt_rt_free_lit(rt->lit);
	mrt_rt_free_geo(rt->geo);
	free(rt);
	return (NULL);
}