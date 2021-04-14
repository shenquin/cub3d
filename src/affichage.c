/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:15:57 by shenquin          #+#    #+#             */
/*   Updated: 2021/04/14 14:04:37 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		delt_calc(t_pos *pos)
	{
		if (pos->dir_y == 0)
			pos->deltadist_x = 0;
		else
		{
			if (pos->dir_x == 0)
				pos->deltadist_x = 1;
			else
				pos->deltadist_x = fabs(1 / pos->dir_x);
		}
		if (pos->dir_x == 0)
			pos->deltadist_y = 0;
		else
		{
			if (pos->dir_y == 0)
				pos->deltadist_y = 1;
			else
				pos->deltadist_y = fabs(1 / pos->dir_y);
		}
	}

void		move_dir(t_pos *pos)
{
	if (pos->raydir_x < 0)
		{
			pos->step_x = -1;
			pos->sidedist_x = (pos->pos_x - pos->map_x) * pos->deltadist_x;
		}
		else 
		{
			pos->step_x = 1;
			pos->sidedist_x = (pos->map_x + 1 - pos->pos_x) * pos->deltadist_x;
		}
		if (pos->raydir_y < 0)
		{
			pos->step_y = -1;
			pos->sidedist_y = (pos->pos_y - pos->map_y) * pos->deltadist_y;
		}
		else
		{
			pos->step_y = 1;
			pos->sidedist_y = (pos->map_y + 1 - pos->pos_y) * pos->deltadist_y;
		}
}

void		init_dir_param(t_pos *pos, t_data *data)
{
	pos->camera_x = 2 * pos->x / data->reso_x - 1;
	pos->raydir_x = pos->dir_x + pos->plane_x * pos->camera_x;
	pos->raydir_y = pos->dir_y + pos->plane_y * pos->camera_x;
	pos->map_x = pos->pos_x;
	pos->map_y = pos->pos_y;
}

void		init_base_param(t_pos *pos)
{
	pos->pos_x = 12;
	pos->pos_y = 22;
	pos->dir_x = -1;
	pos->dir_y = 0;
	pos->plane_x = 0;
	pos->plane_y = 0.66;
}

void		movement(t_pos *pos, t_data *data, t_map *map)
{
	init_struct_pos();
	init_base_param(pos);
	while (pos->x++ < data->reso_x)
	{
		init_dir_param(pos, data);
		delt_calc(pos);
		move_dir(pos);
		move_wall(pos, data);
		perp_calc(pos);
		line_to_wall(pos);
		color_asign(map, pos, data);
	}
}