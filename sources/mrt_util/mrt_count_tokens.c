/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_count_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:32:27 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 18:35:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_count_tokens(char **tokens)
{
	int	count;

	count = 0;
	if (tokens == NULL)
		return (count);
	while (*(tokens + count) != NULL)
		++count;
	return (count);
}
