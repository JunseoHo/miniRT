/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:13 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 21:03:44 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

char	*mrt_parse_color_content(int *c, char *s)
{
	*c = 0;
	while (mrt_isdigit(*s))
	{
		*c = (*c) * 10 + (*s - '0');
		++s;
	}
	if (c > 255)
		return (NULL);
	return (s);
}

t_color	*mrt_parse_color(char *s)
{
	t_color	*c;

	c = mrt_color_malloc();
	if (c == NULL)
		return (NULL);
	s = mrt_parse_color_content(&(c->r), s);
	if (s == NULL || *s != ',')
		return (mrt_free_color(c));
	++s;
	s = mrt_parse_color_content(&(c->g), s);
	if (s == NULL || *s != ',')
		return (mrt_free_color(c));
	++s;
	s = mrt_parse_color_content(&(c->b), s);
	if (s == NULL || *s != '\0')
		return (mrt_free_color(c));
	return (c);
}
