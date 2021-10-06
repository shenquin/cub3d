/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:39:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/04 14:38:57 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_right(t_data *data)
{
	if (data->map[(int)(data->posy +
		data->dirx * 0.5)][(int)data->posx] != '1')
		data->posy += data->dirx * data->movespeed;
	if (data->map[(int)data->posy][(int)(data->posx -
		data->diry * 0.5)] != '1')
		data->posx -= data->diry * data->movespeed;
	
}

void	rot_right(t_data *data)
{
	data->olddirx = data->dirx;
	data->dirx = data->dirx * cos(data->rotspeed) -
		data->diry * sin(data->rotspeed);
	data->diry = data->olddirx * sin(data->rotspeed) +
		data->diry * cos(data->rotspeed);
	data->oldplanex = data->planex;
	data->planex = data->planex * cos(data->rotspeed) -
		data->planey * sin(data->rotspeed);
	data->planey = data->oldplanex * sin(data->rotspeed) +
		data->planey * cos(data->rotspeed);
}

void	rot_left(t_data *data)
{
	data->olddirx = data->dirx;
	data->dirx = data->dirx * cos(-(data->rotspeed)) - data->diry *
		sin(-(data->rotspeed));
	data->diry = data->olddirx * sin(-(data->rotspeed)) + data->diry *
		cos(-(data->rotspeed));
	data->oldplanex = data->planex;
	data->planex = data->planex * cos(-(data->rotspeed)) - data->planey *
		sin(-(data->rotspeed));
	data->planey = data->oldplanex * sin(-(data->rotspeed)) + data->planey *
		cos(-(data->rotspeed));
}

void	move_left(t_data *data)
{
	if (data->map[(int)(data->posy -
		data->dirx * 0.5)][(int)data->posx] != '1')
		data->posy -= data->dirx * data->movespeed;
	if (data->map[(int)data->posy][(int)(data->posx +
		data->diry * 0.5)] != '1')
		data->posx += data->diry * data->movespeed;
}
