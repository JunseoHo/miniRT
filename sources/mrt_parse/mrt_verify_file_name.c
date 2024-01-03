/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify_file_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:31:59 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 08:35:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_verify_file_name(char *name)
{
	int	len;

	len = mrt_strlen(name);
	if (len < 4)
		return (0);
	if (name[len - 3] != '.' || name[len - 2] != 'r' || name[len - 1] != 't')
		return (0);
	return (1);
}
