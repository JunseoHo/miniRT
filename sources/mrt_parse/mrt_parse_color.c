/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:13 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 20:16:21 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_parse_color_content(int *c, char *s)
{
	while (mrt_isdigit(*s))
	{
		*c = (*c) * 10 + (*s - '0');
		++s;
	}
}

t_color	*mrt_parse_color(char *s)
{
	t_color	*c;

	c = mrt_color_malloc();
	if (c == NULL)
		return (NULL);
	while (*s >= '0' && *s <= '9')
	{
		c->r = (c->r) * 10 + (*s - '0');
		++s;
		if (c->r > 255)
			return (mrt_color_free(c));
	}
	if (*s != ',')
		return (mrt_color_free(c));
	++s;
	return (0);
}
