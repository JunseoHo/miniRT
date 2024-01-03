/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:19:18 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 10:03:04 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	main(int argc, char *argv[])
{
	t_rt	*rt;

	rt = mrt_parse(argc, argv);
	if (rt == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	mrt_print_rt(rt);
	return (0);
}
