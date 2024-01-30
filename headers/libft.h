/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:26:14 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:01:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	TRUE = 0,
	FALSE = 1,
}	t_bool;

void	ft_except(char *msg, int stat);
int		ft_isdigit(int c);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strrchr(char *s, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_substr(char *s, size_t begin, size_t end);
char	*ft_token(char *line, size_t target_index);

#endif