/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_add_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:20:39 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 14:21:39 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

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
