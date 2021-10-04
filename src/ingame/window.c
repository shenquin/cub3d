/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:45 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/04 14:34:39 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_cpy(t_data *data, t_img *img)
{
	int i;

	i = 0;
	img->map = malloc(sizeof(char *) * data->nb_line);
	if (!img->map)
		exit_error("img->map malloc failed");
	while (i < data->nb_line)
	{
		img->map[i] = ft_strdup(data->map[i]);
		i++;
	}
	img->position = malloc(sizeof(char) * 1);
	printf("::::::::::::::::::::::::::::::::::::%c\n", data->position);
	img->position = &data->position;
	printf("::::::::::::::::::::::::::::::::::::%s\n", img->position);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_data *data)
{
	t_img	img;

	img.mlx = mlx_init();
	get_pos(data, &img);
	map_cpy(data, &img);
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
	/*mlx_hook(img.win, 17, 1L << 17, ft_esc, &img);
	mlx_hook(img.win, 15, 1L << 16, ft_visible, &img);*/
	mlx_loop(img.mlx);
}
