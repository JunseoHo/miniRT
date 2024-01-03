/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_geo_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:23:50 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:28:27 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_geo	*mrt_geo_malloc(t_geo_type type)
{
	t_geo	*geo;

	geo = malloc(sizeof(t_geo));
	if (geo == NULL)
		mrt_exit("malloc failed.");
	geo->type = type;
	geo->pos = NULL;
	geo->ori = NULL;
	geo->next = NULL;
	return (geo);
}
