/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rt_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:31:35 by jho               #+#    #+#             */
/*   Updated: 2024/01/16 10:49:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mrt.h"

void	mrt_rt_pixel_put()
{
	
}

void	mrt_rt_show(t_rt *rt)
{
	void	*ptr;
	void	*win;
	int		bpp;
	int		len;
	void	*img;
	int 	end;
	char	*addr;
	char	*loc;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 1000, 1000, "miniRT");
	img = mlx_new_image(ptr, 1000, 1000);
	addr = mlx_get_data_addr(img, &bpp, &len, &end);
	for (size_t i = 0; i < 1000; i++)
	{
		for (size_t j= 0; j < 1000; j++)
		{
			loc = addr + (j * len + i * bpp / 8);
			*(unsigned int *)loc = rt->buffer[j][i];
		}
	}
	mlx_put_image_to_window(ptr, win, img, 0, 0);
	mlx_loop(ptr);
}