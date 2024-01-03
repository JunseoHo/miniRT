/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:30:31 by jho               #+#    #+#             */
/*   Updated: 2024/01/03 09:17:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_object(t_rt *rt, char **tokens)
{
	int	stat;

	if (mrt_strcmp(tokens[0], "A"))
		stat = mrt_parse_amb(rt, tokens);
	else if (mrt_strcmp(tokens[0], "C"))
		stat = mrt_parse_cam(rt, tokens);
	else if (mrt_strcmp(tokens[0], "L"))
		stat = mrt_parse_lit(rt, tokens);
	//else if (mrt_strcmp(tokens[0], "sp"))
	//	stat = mrt_parse_sp(rt, tokens);
	//else if (mrt_strcmp(tokens[0], "pl"))
	//	stat = mrt_parse_pl(rt, tokens);
	//else if (mrt_strcmp(tokens[0], "cy"))
	//	stat = mrt_parse_cy(rt, tokens);
	else
		stat = 0;
	return (stat);
}

t_rt	*mrt_parse_file(int fd)
{
	char	*line;
	char	**tokens;
	t_rt	*rt;

	rt = mrt_rt_malloc();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tokens = mrt_split(line, ' ');
		free(line);
		if (tokens == NULL)
			mrt_exit("malloc failed.");
		if (!mrt_parse_object(rt, tokens))
		{
			free(tokens);
			return (mrt_rt_free(rt));
		}
		mrt_free_tokens(tokens);
	}
	return (rt);
}
