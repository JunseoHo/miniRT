/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:09:29 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 16:05:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

bool	mrt_load(t_mrt *mrt, int argc, char **argv)
{
	int		fd;
	char	*line;
	bool	b_parse_success;

	if (argc != 2 || !mrt_verify_extension(argv[1]))
		return (false);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		mrt_except("File open error.", errno);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		b_parse_success = mrt_parse(mrt, line);
		free(line);
		if (!b_parse_success)
			break ;
	}
	if (close(fd) == -1)
		mrt_except("File close error.", errno);
	return (b_parse_success);
}
