/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:45:17 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/23 14:10:47 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	verifmapline(char *line)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != 'N'
		&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E' && line[i] != ' ' )
			exit_error("Invalid map");
		i++;
	}
	if (line[i - 1] != '1')
		exit_error("Invalid map");
}

void	checkifhole(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->nb_line)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
			{
				if (data->map[i][j - 1] != '1')
					exit_error("Hole in map");
				else if (data->map[i][j + 1] != '1')
					exit_error("Hole in map");
				else if (data->map[i - 1][j] != '1')
					exit_error("Hole in map");
				else if (data->map[i + 1][j] != '1')
					exit_error("Hole in map");
			}
			j++;
		}
		i++;
	}
}