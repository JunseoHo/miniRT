/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:57:25 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 08:35:18 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_rt	*mrt_parse(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		return (NULL);
	if (!mrt_verify_file_name(argv[1]))
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		mrt_exit("File open failed.");
	return (mrt_parse_file(fd));
}
