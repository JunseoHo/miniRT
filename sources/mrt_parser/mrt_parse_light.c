/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:42 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 14:05:42 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	void	mrt_parse_add_lit(t_lit **lits, t_lit *lit)
{
	t_lit	*last;

	if (*lits == NULL)
		*lits = lit;
	else
	{
		last = *lits;
		while (last->next != NULL)
			last = last->next;
		last->next = lit;
	}
}

static	t_lit	*init_light(void)
{
	t_lit	*lit;

	lit = malloc(sizeof(t_lit));
	if (lit == NULL)
		ft_except("Malloc failed.", errno);
	lit->next = NULL;
	return (lit);
}

t_bool	mrt_parse_light(t_lit **lits, char *line)
{
	t_lit	*lit;

	lit = init_light();
	if (mrt_parse_vector(&(lit->origin), line, 1) == FALSE)
		return (FALSE);
	if (mrt_parse_double(&(lit->brightness), line, '\0', 2) == FALSE)
		return (FALSE);
	if (mrt_parse_color(&(lit->color), line, 3) == FALSE)
		return (FALSE);
	mrt_parse_add_lit(lits, lit);
	return (TRUE);
}
