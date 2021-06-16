/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:04 by namenega          #+#    #+#             */
/*   Updated: 2021/06/16 11:25:23 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
** Move left if no wall in front of you
*/

void		ft_mvleft(t_pos *pos, t_map *map)
{
	double i;
	double j;

	i = 0.2 - (0.4 * (pos->dir.y > 0));
	j = 0.2 - (0.4 * (pos->dir.x < 0));
	if (map->real_map[(int)map->x][(int)(map->y + j)] == 7)
		map->y += pos->dir.x * MS;
	if (map->real_map[(int)(map->x + i)][(int)map->y] == 7)
		map->x -= pos->dir.y * MS;
}

/*
** Move right if no wall in front of you
*/

void		ft_mvright(t_pos *pos, t_map *map)
{
	double i;
	double j;

	i = 0.2 - (0.4 * (pos->dir.y < 0));
	j = 0.2 - (0.4 * (pos->dir.x > 0));
	if (map->real_map[(int)(map->x + i)][(int)map->y] == 7)
		map->x += pos->dir.y * MS;
	if (map->real_map[(int)map->x][(int)(map->y + j)] == 7)
		map->y -= pos->dir.x * MS;
}
