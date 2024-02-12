/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:42 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 15:28:03 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	mrt_parse_light(t_lit *lit, char *line)
{
	if (lit->b_init == TRUE)
		return (FALSE);
	if (mrt_parse_vector(&(lit->origin), line, 1) == FALSE)
		return (FALSE);
	if (mrt_parse_double(&(lit->brightness), line, '\0', 2) == FALSE)
		return (FALSE);
	if (mrt_parse_color(&(lit->color), line, 3) == FALSE)
		return (FALSE);
	lit->b_init = TRUE;
	return (TRUE);
}
