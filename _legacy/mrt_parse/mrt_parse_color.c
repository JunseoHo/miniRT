/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:13 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:06:10 by jho              ###   ########.fr       */
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
		return (mrt_color_free(c));
	++s;
	s = mrt_parse_color_content(&(c->g), s);
	if (s == NULL || *s != ',')
		return (mrt_color_free(c));
	++s;
	s = mrt_parse_color_content(&(c->b), s);
	if (*s == '\n')
		++s;
	if (s == NULL || *s != '\0')
		return (mrt_color_free(c));
	return (c);
}
