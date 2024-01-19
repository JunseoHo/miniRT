/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:08:30 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 14:48:59 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_light(t_light *light, char *line)
{
	char	*token;
	bool	b_parse_success;

	token = mrt_token(line, 1);
	b_parse_success = mrt_parse_vector(&(light->position), token);
	free(token);
	token = mrt_token(line, 2);
	b_parse_success &= mrt_parse_double(&(light->brightness), token, '\0');
	free(token);
	token = mrt_token(line, 3);
	b_parse_success &= mrt_parse_color(&(light->color), token);
	free(token);
	return (true);
}
