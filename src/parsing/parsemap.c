/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:35:41 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/19 15:25:48 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	allocmap(t_data *data, int fd)
{
	int		i;
	char	*line2;

	i = 0;
	line2 = NULL;
	while (get_next_line(fd, &line2) > 0)
	{
		if (line2[0] == '0')
			exit_error("Invalid map");
		if (line2[0] == '1' || (line2[0] == ' ' && checkifmap2(line2)))
			data->nb_line++;
		if (ft_strlen(line2) > (size_t)data->map_len)
			data->map_len = ft_strlen(line2);
		free(line2);
	}
	if (line2[0] == '1' || (line2[0] == ' ' && checkifmap2(line2)))
		data->nb_line++;
	if (ft_strlen(line2) > (size_t)data->map_len)
		data->map_len = ft_strlen(line2);
	free(line2);
	data->map = malloc(sizeof(char *) * data->nb_line);
	if (!data->map)
		exit_error("fail with memory allocation");
}

void	parsemap2(char *line, t_data *data, int i)
{
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
		{
			if (data->position == 0)
				data->position = line[i];
			else
				exit_error("Too much spawn");
		}
		i++;
	}
}

void	parsemap(char *line, t_data *data)
{
	int	i;

	i = 0;
	parsemap2(line, data, i);
	verifmapline(line);
	data->map[data->line_place] = ft_calloc(sizeof(char), data->map_len + 1);
	i = 0;
	while (i < data->map_len)
	{
		if (line[i] == '\0')
			break ;
		data->map[data->line_place][i] = line[i];
		i++;
	}
	while (i < data->map_len)
	{
		data->map[data->line_place][i] = ' ';
		i++;
	}
	data->line_place++;
	data->existmap = 1;
}
