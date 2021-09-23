/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:45 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/23 16:40:38 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(void)
{
	t_img	img;

	img.mlx = mlx_init();
	if (!(img.win))
		exit_error("Window creation failed");
	img.win = mlx_new_window(img.mlx, 720, 480, "cub3d");
	if (!(img.win))
		exit_error("Window creation failed");
	img.img = mlx_new_image(img.mlx, 720, 480);
	if (!(img.win))
		exit_error("Window creation failed");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								&img.line_length, &img.endian);
	if (!(img.win))
		exit_error("Window creation failed");
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, KEYPRESS, 1L << 0, key_read, &img);
	//mlx_hook(img.win, 17, 1L << 17, ft_esc, &img);
	//mlx_hook(img.win, 15, 1L << 16, ft_visible, &img);
	mlx_loop(img.mlx);
}
