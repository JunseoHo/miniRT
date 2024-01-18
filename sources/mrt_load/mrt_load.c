/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:09:29 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 15:26:47 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_load(t_mrt *mrt, int argc, char **argv)
{
	mrt = NULL;
	if (argc != 2 || !mrt_verify_extension(argv[1]))
		return (false);
	return (true);
}
