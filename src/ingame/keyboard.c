/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:03 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/02 19:16:29 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	backward(t_img *img)
{
	if (img->map[img->posy][(int)(img->posx - img->dirx *
		img->movespeed)] != '1')
		img->posx -= img->dirx * img->movespeed;
	if (img->map[(int)(img->posy - img->diry * img->movespeed)]
		[img->posx] != '1')
		img->posy -= img->diry * img->movespeed;
}

void	foreward(t_img *img)
{
	if (img->map[img->posy][(int)(img->posx + img->dirx *
		img->movespeed)] != '1')
		img->posx += img->dirx * img->movespeed;
	if (img->map[(int)(img->posy + img->diry * img->movespeed)]
		[img->posx] != '1')
		img->posy += img->diry * img->movespeed;
}

void	assign_pos2(t_img *img)
{
	if (img->position == 'N')
	{
		img->planex = 0.66;
		img->planey = 0;
		img->dirx = 0;
		img->diry = -1;
		img->pos = 1;
	}
	if (img->position == 'S')
	{
		img->planex = -0.66;
		img->planey = 0;
		img->dirx = 0;
		img->diry = 1;
		img->pos = 1;
	}
	img->map[img->posx][img->posy] = '0';
	img->comptpos = 1;
}

void	assign_pos(t_img *img)
{
	img->movespeed = 0.2;
	img->rotspeed = 0.17;
	img->posy += 0.5;
	img->posx += 0.5;
	printf("%c", img->position);
	if (img->position == 'E')
	{
		img->planex = 0;
		img->planey = 0.66;
		img->dirx = 1;
		img->diry = 0;
		img->pos = 1;
	}
	if (img->position == 'W')
	{
		img->planex = 0;
		img->planey = -0.66;
		img->dirx = -1;
		img->diry = 0;
		img->pos = 1;
	}
	assign_pos2(img);
}

int	key_read(int keycode, t_img *img)
{
	assign_pos(img);
	if (keycode == KEYCODE_ESC)
		exit (0);
	if (keycode == KEYCODE_W || keycode == KEYCODE_UPARROW)
		foreward(img);
	if (keycode == KEYCODE_S || keycode == KEYCODE_DOWNARROW)
		backward(img);
	if (keycode == KEYCODE_A)
		move_left(img);
	if (keycode == KEYCODE_LEFTARROW)
		rot_left(img);
	if (keycode == KEYCODE_D)
		move_right(img);
	if (keycode == KEYCODE_RIGHTARROW)
		rot_right(img);
	//if (raycasting(img) == -1)
	//	exit_error("raycasting has failed");
//	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
