/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:30:31 by jho               #+#    #+#             */
/*   Updated: 2023/12/29 18:06:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

int	mrt_parse_route(t_rt *rt, char **tokens)
{
	int	stat;

	if (mrt_strcmp(tokens[0], "A"))
		stat = mrt_parse_amb(rt, tokens);
	else if (mrt_strcmp(tokens[0], "C"))
		stat = mrt_parse_cam(rt, tokens);
	else if (mrt_strcmp(tokens[0], "L"))
		stat = mrt_parse_lit(rt, tokens);
	else if (mrt_strcmp(tokens[0], "sp"))
		stat = mrt_parse_sp(rt, tokens);
	else if (mrt_strcmp(tokens[0], "pl"))
		stat = mrt_parse_pl(rt, tokens);
	else if (mrt_strcmp(tokens[0], "cy"))
		stat = mrt_parse_cy(rt, tokens);
	return (stat);
}

t_rt	*mrt_parse_content(int fd)
{
	char	*line;
	char	**tokens;
	t_rt	*rt;

	rt = mrt_rt_malloc();
	if (rt == NULL)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tokens = mrt_split(line, ' ');
		free(line);
		if (tokens == NULL)
			return (mrt_rt_free(rt));
		if (!mrt_parse_route(rt, tokens))
		{
			free(tokens);
			return (mrt_rt_free(rt));
		}
		mrt_free_tokens(tokens);
	}
	return (rt);
}
