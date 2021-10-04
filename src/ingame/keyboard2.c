/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:39:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/02 19:14:28 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_right(t_img *img)
{
	if (img->map[(int)(img->posy +
		img->dirx * 0.5)][(int)img->posx] != '1')
		img->posy += img->dirx * img->movespeed;
	if (img->map[(int)img->posy][(int)(img->posx -
		img->diry * 0.5)] != '1')
		img->posx -= img->diry * img->movespeed;
	
}

void	rot_right(t_img *img)
{
	img->olddirx = img->dirx;
	img->dirx = img->dirx * cos(img->rotspeed) -
		img->diry * sin(img->rotspeed);
	img->diry = img->olddirx * sin(img->rotspeed) +
		img->diry * cos(img->rotspeed);
	img->oldplanex = img->planex;
	img->planex = img->planex * cos(img->rotspeed) -
		img->planey * sin(img->rotspeed);
	img->planey = img->oldplanex * sin(img->rotspeed) +
		img->planey * cos(img->rotspeed);
}

void	rot_left(t_img *img)
{
	img->olddirx = img->dirx;
	img->dirx = img->dirx * cos(-(img->rotspeed)) - img->diry *
		sin(-(img->rotspeed));
	img->diry = img->olddirx * sin(-(img->rotspeed)) + img->diry *
		cos(-(img->rotspeed));
	img->oldplanex = img->planex;
	img->planex = img->planex * cos(-(img->rotspeed)) - img->planey *
		sin(-(img->rotspeed));
	img->planey = img->oldplanex * sin(-(img->rotspeed)) + img->planey *
		cos(-(img->rotspeed));
}

void	move_left(t_img *img)
{
	if (img->map[(int)(img->posy -
		img->dirx * 0.5)][(int)img->posx] != '1')
		img->posy -= img->dirx * img->movespeed;
	if (img->map[(int)img->posy][(int)(img->posx +
		img->diry * 0.5)] != '1')
		img->posx += img->diry * img->movespeed;
}
