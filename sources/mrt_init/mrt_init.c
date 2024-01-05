/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:43:40 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:25:24 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

static bool	mrt_verify_file_name(char *name)
{
	int	len;

	len = mrt_strlen(name);
	if (len < 4)
		return (0);
	if (name[len - 3] != '.' || name[len - 2] != 'r' || name[len - 1] != 't')
		return (false);
	return (true);
}

bool	mrt_init(t_rt *rt, int argc, char **argv)
{
	bool	b_stat;
	int		arg_fd;

	if (argc != 2 || !mrt_verify_file_name(argv[1]))
		return (false);
	arg_fd = open(argv[1], O_RDONLY);
	if (arg_fd == -1)
		mrt_exit("file open failed.", errno);
	b_stat = mrt_init_rt(rt, arg_fd);
	if (close(arg_fd) == -1)
		mrt_exit("file close failed.", errno);
	return (b_stat);
}
