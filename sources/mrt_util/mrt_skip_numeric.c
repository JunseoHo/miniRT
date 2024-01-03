/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_skip_numeric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:08:43 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 09:17:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

char	*mrt_skip_numeric(char *s)
{	
	int	dec_pt;

	if (s == NULL)
		return (NULL);
	dec_pt = 0;
	while (mrt_isdigit(*s))
		++s;
	if (*s == '.' && mrt_isdigit(*(s + 1)))
	{
		++s;
		while (*s >= '0' && *s <= '9')
			++s;
	}
	return (s);
}