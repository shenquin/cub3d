/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:40:15 by shenquin          #+#    #+#             */
/*   Updated: 2021/04/14 13:57:44 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		perp_calc(t_pos *pos)
{
	if (pos->side == 0)
		pos->perpwalldist = (pos->map_x - pos->pos_x + (1 - pos->step_x) / 2) / pos->raydir_x;
	else
		pos->perpwalldist = (pos->map_y - pos->pos_y + (1 - pos->step_y) / 2) / pos->raydir_y;
	
}

void		move_wall(t_pos *pos, t_data *data)
{
	while(pos->hit == 0)
	{
		if(pos->sidedist_x < pos->sidedist_y)
		{
			pos->sidedist_x += pos->deltadist_x;
			pos->map_x += pos->step_x;
			pos->side = 0;
		}
		else
		{
			pos->sidedist_y += pos->deltadist_y;
			pos->map_y += pos->step_y;
			pos->side = 1;
		}
		if (data->worldmap[pos->map_x][pos->map_y] != '0')
			pos->hit = 1;
	}
}

void		line_to_wall(t_pos *pos, t_data *data)
{
	pos->line_height = data->reso_y / pos->perpwalldist;
	pos->draw_start = -(pos->line_height) / 2 + data->reso_y / 2;
	if (pos->draw_start < 0)
		pos->draw_start = 0;
	pos->draw_end = pos->line_height / 2 + data->reso_y / 2;
	if (pos->draw_end >= data->reso_y)
		pos->draw_end = data->reso_y - 1;
}

void		color_asign(t_map *map, t_pos *pos, t_data *data)
{
	if (map->real_map[(int)pos->map_x][(int)pos->map_y] == 1)
	{
		map->color_r = 0x00800000;
		map->color_g = 0;
		map->color_b = 0x0000ff;
	}
	map->colorc_b = data->ceiling_blue;;
	map->colorc_g = data->ceiling_green * 256;
	map->colorc_r = data->ceiling_red * 65536;
	map->colorf_b = data->floor_blue;
	map->colorf_g = data->floor_green * 256;
	map->colorf_r = data->floor_red * 65536;
}
