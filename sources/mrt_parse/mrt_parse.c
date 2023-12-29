/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:57:25 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 15:30:09 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

t_rt	*mrt_parse(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	return (mrt_parse_content(fd));
}