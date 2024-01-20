/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:13:28 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 16:00:35 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_verify_extension(char *filename)
{
	size_t	len;

	len = mrt_strlen(filename);
	return (len > 3
		&& filename[len - 3] == '.'
		&& filename[len - 2] == 'r'
		&& filename[len - 1] == 't');
}
