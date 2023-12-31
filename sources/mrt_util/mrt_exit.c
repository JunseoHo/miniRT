/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:23:25 by jho               #+#    #+#             */
/*   Updated: 2024/01/05 09:56:58 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_exit(char *message, int exit_status)
{
	write(2, message, mrt_strlen(message));
	write(2, "\n", 1);
	exit(exit_status);
}
