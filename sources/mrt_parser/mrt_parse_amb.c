/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_amb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:41:48 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 13:44:31 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	mrt_parse_amb(t_amb *amb, char *line)
{
	if (amb->b_init == TRUE)
		return (FALSE);
	if (mrt_parse_double(&(amb->ratio), line, '\0', 1) == FALSE)
		return (FALSE);
	if (mrt_parse_color(&(amb->color), line, 2) == FALSE)
		return (FALSE);
	amb->b_init = TRUE;
	return (TRUE);
}
