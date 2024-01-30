/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_file_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:45:41 by sejkim2           #+#    #+#             */
/*   Updated: 2024/01/25 14:24:58 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

static	bool	mrt_verify_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len > 3
		&& filename[len - 3] == '.'
		&& filename[len - 2] == 'r'
		&& filename[len - 1] == 't');
}

bool	mrt_file_parse(t_mrt *mrt, int argc, char **argv)
{
	int		fd;
	char	*line;
	bool	b_parse_success;

	if (argc != 2 || !mrt_verify_extension(argv[1]))
		return (false);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_except("File open error.", errno);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		b_parse_success = mrt_parse_line(mrt, line);
		free(line);
		if (!b_parse_success)
			break ;
	}
	if (close(fd) == -1)
		ft_except("File close error.", errno);
	return (b_parse_success);
}
