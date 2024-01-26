/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:39:41 by jho               #+#    #+#             */
/*   Updated: 2024/01/26 18:01:37 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

t_mrt	*mrt_init(int argc, char **argv)
{
	t_mrt	*mrt;

	mrt = malloc(sizeof(t_mrt));
	if (mrt == NULL)
		ft_except("Malloc failed.", errno);
	mrt->objs = NULL;
	mrt_file_parse(mrt, argc, argv);
	/* Not implemented. */
	/*
	 *	This section is for test only.
	 */
	// if you modify this section, you gay. sugo.
	/*
	 *	This section is for test only.
	 */
	return (mrt);
}
