/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:45 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/06 18:16:16 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_visible(t_data *data)
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

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	(void)color;
	(data->addr)[y * (data->pxl_line) + x] = color;
}*/

int	get_pos(t_data *data)
{
	double	i;
	double	j;

	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->map[(int)i][(int)j])
		{
			if (data->map[(int)i][(int)j] == 'N' || data->map[(int)i][(int)j] == 'S'
				|| data->map[(int)i][(int)j] == 'W' || data->map[(int)i][(int)j] == 'E')
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

void	keyread(t_data *data)
{
	mlx_hook(data->win, KEYPRESS, 1L << 0, key_read, data);
	mlx_hook(data->win, 17, 1L << 17, ft_esc, data);
	mlx_hook(data->win, 15, 1L << 16, ft_visible, data); //???
}

void	start(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->screenwidth, data->screenheight, "cub3d");
	if (!(data->win))
		exit_error("Window creation failed");
	data->img = mlx_new_image(data->mlx, data->screenwidth, data->screenheight);
	if (!(data->img))
		exit_error("Window creation failed");
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!(data->addr))
		exit_error("Window creation failed");
	if (raycasting(data) == -1)
		exit_error("Window creation failed");
}

void	window(t_data *data)
{
	data->screenwidth = 720;
	data->screenheight = 480;
	get_pos(data);
	assign_pos(data);
	assigntextures(data);
	while (data->mlx != NULL)
	{
		start(data);
		keyread(data);
		mlx_loop(data->mlx);
	}
}
