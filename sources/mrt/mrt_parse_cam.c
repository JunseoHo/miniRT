/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:54:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/25 17:34:01 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

// static size_t	mrt_parse_vector_shift_index(char *token, size_t index)
// {
// 	if (token[index] == '-')
// 		++index;
// 	while (token[index] >= '0' && token[index] <= '9')
// 		++index;
// 	if (token[index] == '.')
// 	{
// 		++index;
// 		while (token[index] >= '0' && token[index] <= '9')
// 			++index;
// 	}
// 	return (index);
// }

// static bool	mrt_parse_vector(t_vec *vec, char *token)
// {
// 	size_t	index;

// 	if (!mrt_parse_double(&(vec->x), token, ','))
// 		return (false);
// 	index = mrt_parse_vector_shift_index(token, 0);
// 	if (!mrt_parse_double(&(vec->y), token + index + 1, ','))
// 		return (false);
// 	index = mrt_parse_vector_shift_index(token, index + 1);
// 	if (!mrt_parse_double(&(vec->z), token + index + 1, '\0'))
// 		return (false);
// 	return (true);
// }

static	bool	mrt_parse_vector(t_vec *vec, char *token)
{
	char	*first_coma;
	char	*second_coma;
	char 	*tmp_token;
	bool	b_parse_success;

	first_coma = ft_str_first_chr(token, ',');
	second_coma = ft_str_last_chr(token, ',');
	if (first_coma == second_coma)
		return (false);
	tmp_token = ft_substr(token, 0, first_coma - token);
	b_parse_success = mrt_parse_double(&vec->x, tmp_token, ',');
}

bool	mrt_parse_cam(t_cam *cam, char *line)
{
	char	*token;
	bool	b_parse_success;	

	token = ft_token(line, 1);
	b_parse_success = mrt_parse_vector(&(cam->eye), token);
	free(token);
	token = ft_token(line, 2);
	b_parse_success &= mrt_parse_vector(&(cam->at), token);
	free(token);
	token = ft_token(line, 3);
	b_parse_success &= mrt_parse_double(&(cam->fov), token, '\0');
	free(token);
	cam->up = vec(0, 1, 0);
	// printf("%f %f %f\n", cam->eye.x, cam->eye.y, cam->eye.z);
	// printf("%f %f %f\n", cam->at.x, cam->at.y, cam->at.z);
	// printf("%f %f %f\n", cam->up.x, cam->up.y, cam->up.z);
	// printf("%f\n", cam->fov);
	// exit(1);
	return (b_parse_success);
}
