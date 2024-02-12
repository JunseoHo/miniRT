/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:45:39 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 14:21:28 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	free_obj(t_obj	*obj)
{
	free(obj);
	return (FALSE);
}

void	free_objs(t_obj *objs)
{
	t_obj	*remove_obj;

	while (objs != NULL)
	{
		remove_obj = objs;
		objs = objs->next;
		free_obj(remove_obj);
	}
}

t_mrt	*mrt_destroy(t_mrt *mrt)
{
	free_objs(mrt->objs);
	free(mrt);
	return (NULL);
}
