/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:19 by jho               #+#    #+#             */
/*   Updated: 2024/01/19 18:17:50 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

int	main(int argc, char **argv)
{
	t_mrt	mrt;

	mrt.objs = NULL;
	if (!mrt_load(&mrt, argc, argv))
		mrt_except("Error", 1);
	mrt_rt(mrt);
	return (0);
}
