/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_except.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:01:51 by jho               #+#    #+#             */
/*   Updated: 2024/01/18 15:26:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt.h"

void	mrt_except(char *message, int exit_code)
{
	write(2, message, mrt_strlen(message));
	write(2, "\n", 1);
	exit(exit_code);
}
