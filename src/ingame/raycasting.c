/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:39 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/06 17:13:51 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	raycast4(t_data *data)
{
	if (data->side == 0)
		data->perpwalldist = (data->mapx - data->posx
				+ (1 - data->stepx) / 2) / data->raydirx;
	else
		data->perpwalldist = (data->mapy - data->posy
				+ (1 - data->stepy) / 2) / data->raydiry;
	data->lineheight = (int)(data->screenheight / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + data->screenheight / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + data->screenheight / 2;
	if (data->drawend >= data->screenheight)
		data->drawend = data->screenheight - 1;
}

void	raycast3(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (data->map[data->mapy][data->mapx] == '1')
			data->hit = 1;
	}
}

void	raycast2(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->posx - data->mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - data->posx) * data->deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->posy - data->mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
	}
}

void	raycast(t_data *data, int a)
{
	data->camerax = 2 * a / (double)data->screenwidth - 1;
	data->raydirx = data->dirx + data->planex * data->camerax;
	data->raydiry = data->diry + data->planey * data->camerax;
	data->mapx = (int)data->posx;
	data->mapy = (int)data->posy;
	data->deltadistx = fabs(1 / data->raydirx);
	data->deltadisty = fabs(1 / data->raydiry);
	data->hit = 0;
}

int	raycasting(t_data *data)
{
	int	a;

	a = 0;
	data->screenwidth = 720;
	data->screenheight = 480;
	data->zbuffer = malloc(sizeof(int *) * data->screenwidth + 1);
	if (!data->zbuffer)
		exit_error("Fail to alloc zbuffer");
	while (a < data->screenwidth)
	{
		raycast(data, a);
		raycast2(data);
		raycast3(data);
		raycast4(data);
		walltexture(data);
		verline(data, a);
		data->zbuffer[a] = data->perpwalldist;
		a++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free(data->zbuffer);
	return (0);
}
