/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_amb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:07:58 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:46:42 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

bool	mrt_init_amb(t_amb *amb, char **tokens)
{
	bool	b_stat;

	if (amb->b_init || tokens[3] != NULL)
		return (false);
	b_stat = (mrt_init_float(&(amb->rat), tokens[1])
			&& mrt_init_color(&(amb->c), tokens[2]));
	if (mrt_verify_float_range(amb->rat, 0.0, 1.0) == false)
		return (false);
	amb->b_init = true;
	return (b_stat);
}
