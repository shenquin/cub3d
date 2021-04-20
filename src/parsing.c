/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:19:53 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 15:59:02 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	parsing(t_data *data, char *line)
{
	//printf("%s\n", line);
	if (line[0] == 'R' && line[1] == ' ')
	{
		if (data->pos_x != 0 || data->pos_y != 0)
			exit_error("Too much R field");
		res(&line[1], data);
	}
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (data->NO != NULL)
			exit_error("Too much NO field");
		north(&line[2], data);
	}
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (data->SO != NULL)
			exit_error("Too much SO field");
		south(&line[2], data);
	}
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		if (data->WE != NULL)
			exit_error("Too much WE field");
		west(&line[2], data);
	}
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (data->EA != NULL)
			exit_error("Too much EA field");
		east(&line[2], data);
	}
	if (line[0] == 'S' && line[1] == ' ')
	{
		if (data->sprite != NULL)
			exit_error("Too much S field");
		sprite(&line[1], data);
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		if (data->ce_r != 0 || data->ce_g != 0 || data->ce_b != 0)
			exit_error("Too much C field");
		ce(&line[1], data);
	}
	if (line[0] == 'F' && line[1] == ' ')
	{
		if (data->fl_r != 0 || data->fl_g != 0 || data->fl_b != 0)
			exit_error("Too much F field");
		fl(&line[1], data);
	}
	if (line[0] == '1')
		return ; //à changer et envoyer dans allocmap(&line[0], data);
	/*else
			exit_error("Parsing data error");*/
}

// mlx_xpm_file_to_image <-- regarde si path invalide
// mettre compteur pour ne pas que la map se fasse parsée trop tot
