/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:38:49 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 18:41:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_axis	*mrt_parse_axis(char *s)
{
	t_axis	*axis;
	char	**tokens;

	axis = malloc(sizeof(t_axis));
	if (axis == NULL)
		return (0);
	tokens = mrt_split(s, ',');
	if (tokens == NULL || mrt_count_tokens(tokens) != 3)
	{
		free(axis);
		mrt_free_tokens(tokens);
		return (0);
	}
}