/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:13 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 18:06:03 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_color(char *s)
{
	int		c;
	char	**tokens;

	c = 0;
	tokens = mrt_split(s, ',');
	if (tokens == NULL)
		return (0);
	c &= mrt_atoi(tokens[0]);
	c <<= 8;
	c &= mrt_atoi(tokens[1]);
	c <<= 8;
	c &= mrt_atoi(tokens[2]);
	mrt_free_tokens(tokens);
	return (0);
}
