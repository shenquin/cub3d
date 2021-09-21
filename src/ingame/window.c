/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:45 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/21 13:30:06 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*int	closewin(t_img *img)
{
	mlx_destroy_window(img->mlx, img->win);
	return 0;
}*/

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
	img.win = mlx_new_window(img.mlx, 1920, 1080, "cub3d");
	if (!(img.win))
		exit_error("Window creation failed");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	if (!(img.win))
		exit_error("Window creation failed");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								&img.line_length, &img.endian);
	if (!(img.win))
		exit_error("Window creation failed");
	//raycasting(data, img);
	my_mlx_pixel_put(&img, 5, 5, 0x000000FF);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
