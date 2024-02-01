/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_add_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:22:47 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/01 14:21:20 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

void	mrt_parse_add_obj(t_obj **objs, t_obj *obj)
{
	t_obj	*last;

	if (*objs == NULL)
		*objs = obj;
	else
	{
		last = *objs;
		while (last->next != NULL)
			last = last->next;
		last->next = obj;
	}
}
