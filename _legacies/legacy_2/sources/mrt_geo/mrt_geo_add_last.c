/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_geo_add_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:12:26 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:30:48 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_geo_add_last(t_geo **list, t_geo *geo)
{
	t_geo	*last;

	if (list == NULL)
		return ;
	if (*list == NULL)
		*list = geo;
	else
	{
		last = *list;
		while (last->next != NULL)
			last = last->next;
		last->next = geo;
	}
}
