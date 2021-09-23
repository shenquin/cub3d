/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:03 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/23 16:53:45 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	rot_left(t_key *key)
{

}

void	move_left(t_key *key)
{
	
}

void	backward(t_key *key)
{

}

void	foreward(t_key *key)
{
	
}

int	key_read(int keycode, t_img *img)
{
	t_key *key;

	key = ft_calloc2(sizeof(t_key));
	if (keycode == KEYCODE_ESC)
		exit (0);
	if (keycode == KEYCODE_W || keycode == KEYCODE_UPARROW)
		foreward(key);
	if (keycode == KEYCODE_S || keycode == KEYCODE_DOWNARROW)
		backward(key);
	if (keycode == KEYCODE_A)
		move_left(key);
	if (keycode == KEYCODE_LEFTARROW)
		rot_left(key);
	if (keycode == KEYCODE_D)
		move_right(key);
	if (keycode == KEYCODE_RIGHTARROW)
		rot_right(key);
	/*if (raycasting(img) == -1)
		exit_error("raycasting has failed");
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);*/
	return (0);
}
