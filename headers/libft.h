/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:26:14 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 14:26:01 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
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