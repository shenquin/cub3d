/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:19:53 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/17 15:22:34 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parsing3(t_data *data, char *line)
{
	if (line[0] == '1')
	{
		if (data->map_argnb != 6)
			exit_error("Invalid map");
		parsemap(line, data);
	}
	else if (line[0] == ' ')
	{
		checkifmap(line, data);
	}
	else if (line[0] == 0)
		return ;
}

void	parsing2(t_data *data, char *line)
{
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (data->EA != NULL)
			exit_error("Too much EA field");
		east(&line[2], data);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		check_comma(line);
		if (data->ce_r != 0 || data->ce_g != 0 || data->ce_b != 0)
			exit_error("Too much C field");
		ce(&line[1], data);
	}
	else if (line[0] == 'F' && line[1] == ' ')
	{
		check_comma(line);
		if (data->fl_r != 0 || data->fl_g != 0 || data->fl_b != 0)
			exit_error("Too much F field");
		fl(&line[1], data);
	}
	parsing3(data, line);
}

void	parsing(t_data *data, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (data->NO != NULL)
			exit_error("Too much NO field");
		north(&line[2], data);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (data->SO != NULL)
			exit_error("Too much SO field");
		south(&line[2], data);
	}
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		if (data->WE != NULL)
			exit_error("Too much WE field");
		west(&line[2], data);
	}
	parsing2(data, line);
}



/*	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (data->EA != NULL)
			exit_error("Too much EA field");
		east(&line[2], data);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		check_comma(line);
		if (data->ce_r != 0 || data->ce_g != 0 || data->ce_b != 0)
			exit_error("Too much C field");
		ce(&line[1], data);
	}
	else if (line[0] == 'F' && line[1] == ' ')
	{
		check_comma(line);
		if (data->fl_r != 0 || data->fl_g != 0 || data->fl_b != 0)
			exit_error("Too much F field");
		fl(&line[1], data);
	}
	else if (line[0] == '1')
	{
		if (data->map_argnb != 6)
			exit_error("Invalid map");
		parsemap(line, data);
	}
	else if (line[0] == ' ')
	{
		checkifmap(line, data);
	}
	else if (line[0] == 0)
		return ;
	else
		exit_error("Parsing data error");
}*/

// mettre compteur pour ne pas que la map se fasse parsée trop tot
