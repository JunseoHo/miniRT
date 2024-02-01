/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_verify_value_range.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:32:33 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/01 16:48:25 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_bool	verify_range(double value, double min_value, double max_value)
{
	if (value < min_value || value > max_value)
		return (FALSE);
	else
		return (TRUE);
}

static	t_bool	verify_brightness(t_mrt *mrt)
{
	t_bool	b_parse_success;

	b_parse_success = TRUE;
	if (mrt->lits == NULL)
		return (FALSE);
	while (1)
	{
		b_parse_success &= verify_range(mrt->lits->brightness, 0.0, 1.0);
		if (b_parse_success == FALSE)
			return (FALSE);
		if (mrt->lits->next == NULL)
			break ;
		mrt->lits = mrt->lits->next;
	}
	return (b_parse_success);
}

static	t_bool	verify_objs_axis(t_mrt *mrt)
{
	t_bool	b_parse_success;

	b_parse_success = TRUE;
	if (mrt->objs != NULL)
	{
		while (1)
		{
			if (mrt->objs->type == PL || mrt->objs->type == CY)
			{
				b_parse_success &= verify_range(mrt->objs->axis.x, -1, 1);
				b_parse_success &= verify_range(mrt->objs->axis.y, -1, 1);
				b_parse_success &= verify_range(mrt->objs->axis.z, -1, 1);
			}
			if (b_parse_success == FALSE)
				return (FALSE);
			if (mrt->objs->next == NULL)
				break ;
			mrt->objs = mrt->objs->next;
		}
	}
	return (b_parse_success);
}

t_bool	verify_value_range(t_mrt *mrt)
{
	t_bool	b_parse_success;

	b_parse_success = verify_range(mrt->amb.ratio, 0.0, 1.0);
	b_parse_success &= verify_range(mrt->cam.at.x, -1, 1);
	b_parse_success &= verify_range(mrt->cam.at.y, -1, 1);
	b_parse_success &= verify_range(mrt->cam.at.z, -1, 1);
	b_parse_success &= verify_range(mrt->cam.fov, 0, 180);
	b_parse_success &= verify_brightness(mrt);
	b_parse_success &= verify_objs_axis(mrt);
	return (b_parse_success);
}
