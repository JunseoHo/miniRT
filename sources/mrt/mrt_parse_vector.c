/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:30:18 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/26 13:57:46 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_parse_vector(t_vec *vec, char *token)
{
	char	*first_coma;
	char	*second_coma;
	char	*tmp_token;
	bool	b_parse_success;

	first_coma = ft_str_first_chr(token, ',');
	second_coma = ft_str_last_chr(token, ',');
	if (first_coma == second_coma)
		return (false);
	tmp_token = ft_substr(token, 0, first_coma - token + 1);
	b_parse_success = mrt_parse_double(&vec->x, tmp_token, ',');
	free(tmp_token);
	tmp_token = ft_substr(token, first_coma - token + 1, second_coma - token + 1);
	b_parse_success &= mrt_parse_double(&vec->y, tmp_token, ',');
	free(tmp_token);
	tmp_token = ft_substr(token, second_coma - token + 1, ft_strlen(token));
	b_parse_success &= mrt_parse_double(&vec->z, tmp_token, '\0');
	free(tmp_token);
	return (b_parse_success);
}
