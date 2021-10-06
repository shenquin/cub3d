/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:45 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/04 16:58:53 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*int	ft_visible(t_data *data)
{
	if (raycasting(data) == -1)
	{
		write(1, "Error\nError raycasting (visi)\n", 30);
		return (-1);
	}
	return (0);
}

int	ft_esc(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

int	get_pos(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				if (data->posx == 0 && data->posy == 0)
				{
					data->posx = j;
					data->posy = i;
					return (0);
				}
			}	
			j++;
		}
		i++;
	}
	return (0);
}

void	window(t_data *data)
{
	data->mlx = mlx_init();
	get_pos(data);
	data->win = mlx_new_window(data->mlx, 720, 480, "cub3d");
	if (!(data->win))
		exit_error("Window creation failed");
	data->img = mlx_new_image(data->mlx, 720, 480);
	if (!(data->img))
		exit_error("Window creation failed");
	data->addr = (int*)mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
	if (!(data->addr))
		exit_error("Window creation failed");
	if (raycasting(data) == -1)
		exit_error("Window creation failed");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, KEYPRESS, 1L << 0, key_read, data);
	/*mlx_hook(data->win, 17, 1L << 17, ft_esc, data);
	mlx_hook(data->win, 15, 1L << 16, ft_visible, data);*/ //???
	mlx_loop(data->mlx);
}
