/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_add_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:20:39 by jho               #+#    #+#             */
/*   Updated: 2024/01/21 00:33:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_add_obj(t_mrt *mrt, t_obj *obj)
{
	t_obj	*last_obj;

	if (mrt->objs == NULL)
	{
		mrt->objs = obj;
		return ;
	}
	last_obj = mrt->objs;
	while (last_obj->next != NULL)
		last_obj = last_obj->next;
	last_obj->next = obj;
}
