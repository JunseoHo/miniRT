/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_lit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:37:51 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:48:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_lit(t_lit *lit, char **tokens)
{
	bool	b_stat;

	if (lit->b_init || tokens[4] != NULL)
		return (false);
	b_stat = (mrt_init_axis(&(lit->pos), tokens[1])
			&& mrt_init_float(&(lit->br), tokens[2])
			&& mrt_init_color(&(lit->c), tokens[3]));
	if (mrt_verify_float_range(lit->br, 0.0, 1.0) == false)
		return (false);
	lit->b_init = true;
	return (b_stat);
}
