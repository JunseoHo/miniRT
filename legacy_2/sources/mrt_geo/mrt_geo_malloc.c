/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_geo_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:59:09 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 11:17:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_geo	*mrt_geo_malloc(t_geo_type type)
{
	t_geo	*geo;

	geo = malloc(sizeof(t_geo));
	if (geo == NULL)
		mrt_exit("malloc failed.", errno);
	geo->type = type;
	geo->next = NULL;
	return (geo);
}
