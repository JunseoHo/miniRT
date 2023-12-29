/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_color_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:58:01 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 20:00:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_color	*mrt_color_malloc(void)
{
	t_color	*c;

	c = malloc(sizeof(t_color));
	if (c == NULL)
		return (NULL);
	c->r = 0;
	c->g = 0;
	c->b = 0;
	return (c);
}
