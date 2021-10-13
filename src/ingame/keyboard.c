/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:03 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/13 16:28:01 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	backward(t_data *data)
{
	if (data->map[(int)data->posy][(int)(data->posx - data->dirx
		* data->movespeed)] != '1')
		data->posx -= data->dirx * data->movespeed;
	if (data->map[(int)(data->posy - data->diry * data->movespeed)]
		[(int)data->posx] != '1')
		data->posy -= data->diry * data->movespeed;
}

void	foreward(t_data *data)
{
	if (data->map[(int)data->posy][(int)(data->posx + data->dirx
		* data->movespeed)] != '1')
		data->posx += data->dirx * data->movespeed;
	if (data->map[(int)(data->posy + data->diry * data->movespeed)]
		[(int)data->posx] != '1')
		data->posy += data->diry * data->movespeed;
}

void	assign_pos2(t_data *data)
{
	if (data->position == 'N')
	{
		data->planex = 0.66;
		data->planey = 0;
		data->dirx = 0;
		data->diry = -1;
		data->posi = 1;
	}
	if (data->position == 'S')
	{
		data->planex = -0.66;
		data->planey = 0;
		data->dirx = 0;
		data->diry = 1;
		data->posi = 1;
	}
	//data->map[(int)data->posx][(int)data->posy] = '0';
	data->comptpos = 1;
}

void	assign_pos(t_data *data)
{
	data->movespeed = 0.2;
	data->rotspeed = 0.17;
	data->posy += 0.5;
	data->posx += 0.5;
	if (data->position == 'E')
	{
		data->planex = 0;
		data->planey = 0.66;
		data->dirx = 1;
		data->diry = 0;
		data->posi = 1;
	}
	if (data->position == 'W')
	{
		data->planex = 0;
		data->planey = -0.66;
		data->dirx = -1;
		data->diry = 0;
		data->posi = 1;
	}
	assign_pos2(data);
}

int	key_read(int keycode, t_data *data)
{
	if (keycode == KEYCODE_ESC)
		exit (0);
	if (keycode == KEYCODE_W || keycode == KEYCODE_UPARROW)
		foreward(data);
	if (keycode == KEYCODE_S || keycode == KEYCODE_DOWNARROW)
		backward(data);
	if (keycode == KEYCODE_A)
		move_left(data);
	if (keycode == KEYCODE_LEFTARROW)
		rot_left(data);
	if (keycode == KEYCODE_D)
		move_right(data);
	if (keycode == KEYCODE_RIGHTARROW)
		rot_right(data);
	if (raycasting(data) == -1)
		exit_error("raycasting has failed");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
