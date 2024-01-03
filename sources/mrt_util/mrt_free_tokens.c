/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_free_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:03:54 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 09:59:18 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_free_tokens(char **tokens)
{
	int index;

	if (tokens == NULL)
		return ;
	index = 0;
	while (*(tokens + index) != NULL)
	{
		free(*(tokens + index));
		++index;
	}
	free(tokens);
}
