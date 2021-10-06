/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:49 by shenquin          #+#    #+#             */
/*   Updated: 2021/10/04 16:02:01 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		walltexture(t_data *data)
{
	if (data->side == 0)
		data->wallx = data->posy + data->perpwalldist * data->raydiry;
	else
		data->wallx = data->posx + data->perpwalldist * data->raydirx;
	data->wallx -= floor((data->wallx));
	data->texx = (int)(data->wallx * (double)data->texwidth);
	if (data->side == 0 && data->raydirx > 0)
		data->texx = data->texwidth - data->texx - 1;
	if (data->side == 1 && data->raydiry < 0)
		data->texx = data->texwidth - data->texx - 1;
	data->step = 1.0 * data->texwidth / data->lineheight;
	data->texpos = (data->drawstart - data->screenheight / 2 +
			data->lineheight / 2) * data->step;
	return (0);
}

void	verline2(t_data *data, int a, int b)
{
	data->texy = (int)data->texpos & (data->texheight - 1);
	data->texpos += data->step;
	if (data->side == 1 && data->raydiry < 0)
		data->color = data->addrno[data->texheight * data->texy + data->texx];
	if (data->side == 1 && data->raydiry > 0)
		data->color = data->addrso[data->texheight * data->texy + data->texx];
	if (data->side == 0 && data->raydirx < 0)
		data->color = data->addrwe[data->texheight * data->texy + data->texx];
	if (data->side == 0 && data->raydirx > 0)
		data->color = data->addrea[data->texheight * data->texy + data->texx];
	data->addr[b * data->screenwidth + a] = data->color;
}

void	verline(t_data *data,int a)
{
	int	b;

	b = 0;
	while (b < data->drawstart)
	{
		data->addr[b * data->screenwidth + a] = data->color_sky;
		b++;
	}
	while (b <= data->drawend)
	{
		verline2(data, a, b);
		b++;
	}
	while (b < data->screenheight)
	{
		data->addr[b * data->screenwidth + a] = data->color_floor;
		b++;
	}
}
