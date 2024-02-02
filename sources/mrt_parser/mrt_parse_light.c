/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:29:42 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/02 15:11:15 by sejkim2          ###   ########.fr       */
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

t_bool	mrt_parse_light(t_lit **lits, char *line)
{
	t_lit	*lit;
	char	*token;
	t_bool	b_parse_success;

	lit = malloc(sizeof(t_lit));
	if (lit == NULL)
		ft_except("Malloc failed.", errno);
	lit->next = NULL;
	token = ft_token(line, 1);
	if (token == NULL)
		return (FALSE);
	b_parse_success = mrt_parse_vector(&(lit->origin), token);
	free(token);
	token = ft_token(line, 2);
	if (token == NULL)
		return (FALSE);
	b_parse_success &= mrt_parse_double(&(lit->brightness), token, '\0');
	free(token);
	token = ft_token(line, 3);
	if (token == NULL)
		return (FALSE);
	b_parse_success &= mrt_parse_color(&(lit->color), token);
	free(token);
	mrt_parse_add_lit(lits, lit);
	return (b_parse_success);
}
