/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_free_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:03:54 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 18:05:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_free_tokens(char **tokens)
{
	if (tokens == NULL)
		return ;
	while (*tokens != NULL)
	{
		free(*tokens);
		++tokens;
	}
	free(tokens);
}