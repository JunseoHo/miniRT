/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:30:18 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 14:29:03 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_bool	mrt_parse_v(t_vec *vec, char *token)
{
	char	*first_coma;
	char	*second_coma;
	char	*tmp_token;
	t_bool	b_parse_success;

	first_coma = ft_strchr(token, ',');
	second_coma = ft_strrchr(token, ',');
	if (!first_coma || !second_coma)
		return (FALSE);
	if (first_coma == second_coma)
		return (FALSE);
	tmp_token = ft_substr(token, 0, first_coma - token + 1);
	b_parse_success = mrt_atod(&vec->x, tmp_token, ',');
	free(tmp_token);
	tmp_token = ft_substr(token, first_coma - token + 1, \
	second_coma - token + 1);
	b_parse_success &= mrt_atod(&vec->y, tmp_token, ',');
	free(tmp_token);
	tmp_token = ft_substr(token, second_coma - token + 1, ft_strlen(token));
	b_parse_success &= mrt_atod(&vec->z, tmp_token, '\0');
	free(tmp_token);
	return (b_parse_success);
}

t_bool	mrt_parse_vector(t_vec *v, char *line, size_t target_index)
{
	char	*token;
	t_bool	b_parse_success;

	token = ft_token(line, target_index);
	b_parse_success = mrt_parse_v(v, token);
	if (token == NULL)
		return (FALSE);
	free(token);
	return (b_parse_success);
}
