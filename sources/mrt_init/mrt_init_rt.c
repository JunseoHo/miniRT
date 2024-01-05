/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:59:06 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 14:49:47 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

static void	mrt_free_tokens(char **tokens)
{
	int	index;

	index = 0;
	while (*(tokens + index) != NULL)
		free(*(tokens + (index++)));
	free(tokens);
}

static bool	mrt_init_object(t_rt *rt, char **tokens)
{
	bool	b_stat;

	if (!mrt_strcmp(tokens[0], "A"))
		b_stat = mrt_init_amb(&(rt->amb), tokens);
	else if (!mrt_strcmp(tokens[0], "C"))
		b_stat = mrt_init_cam(&(rt->cam), tokens);
	else if (!mrt_strcmp(tokens[0], "L"))
		b_stat = mrt_init_lit(&(rt->lit), tokens);
	else if (!mrt_strcmp(tokens[0], "sp"))
		b_stat = mrt_init_sp(&(rt->geo), tokens);
	else if (!mrt_strcmp(tokens[0], "pl"))
		b_stat = mrt_init_pl(&(rt->geo), tokens);
	else if (!mrt_strcmp(tokens[0], "cy"))
		b_stat = mrt_init_cy(&(rt->geo), tokens);
	else
		b_stat = false;
	if (!b_stat)
		printf("Error in %s\n", tokens[0]);
	return (b_stat);
}

bool	mrt_init_rt(t_rt *rt, int fd)
{
	char	*line;
	char	**tokens;
	bool	b_stat;

	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tokens = mrt_split(line, ' ');
		if (tokens == NULL)
			mrt_exit("malloc failed.", errno);
		free(line);
		b_stat = mrt_init_object(rt, tokens);
		mrt_free_tokens(tokens);
		if (!b_stat)
			return (false);
	}
	return (true);
}
