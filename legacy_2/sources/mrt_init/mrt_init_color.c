/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:19:53 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 10:49:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

static char	*mrt_init_color_value(int *result, char *s)
{
	*result = 0;
	while (*s >= '0' && *s <= '9')
	{
		*result = (*result) * 10 + (*s - '0');
		++s;
	}
	if (*result > 255)
		return (NULL);
	return (s);
}

bool	mrt_init_color(t_color *c, char *s)
{
	s = mrt_init_color_value(&(c->r), s);
	if (s == NULL || *(s++) != ',')
		return (false);
	s = mrt_init_color_value(&(c->g), s);
	if (s == NULL || *(s++) != ',')
		return (false);
	s = mrt_init_color_value(&(c->b), s);
	if (s == NULL || (*s != '\0' && *s != '\n'))
		return (false);
	return (true);
}
