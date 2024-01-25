/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:26:14 by jho               #+#    #+#             */
/*   Updated: 2024/01/25 14:07:54 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>

void	ft_except(char *msg, int stat);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, size_t begin, size_t end);
char	*ft_token(char *line, size_t target_index);

#endif