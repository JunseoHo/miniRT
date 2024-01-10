/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:19:18 by jho               #+#    #+#             */
/*   Updated: 2024/01/10 10:10:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	main(int argc, char *argv[])
{
	t_rt	rt;

	if (!mrt_init(&rt, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	mrt_print(rt);
	mrt_rt(&rt);
	mrt_print(rt);
	return (0);
}
