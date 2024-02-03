/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:26:18 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 15:27:17 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	free_lit(t_lit *lit)
{
	free(lit);
	return (FALSE);
}

t_bool	free_obj(t_obj *obj)
{
	free(obj);
	return (FALSE);
}
