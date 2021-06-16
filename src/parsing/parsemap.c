/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:35:41 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/16 11:26:55 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	allocmap(t_data *data, int fd)
{
	int i;
	char *line2;

	i = 0;
	line2 = NULL;
	while (get_next_line(fd, &line2) > 0)
		if (line2[0] == '1' || (line2[0] == ' ' && checkifmap2(line2)))
			data->nb_line++;
	data->map = malloc(sizeof(char*) * data->nb_line);
	if (!data->map)
		exit_error("fail with memory allocation");
}

void	parsemap(char *line, t_data *data)
{
	int i;

	i = 0;
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
	verifmapline(line);
	data->map[data->line_place] = ft_strdup(line);
	data->line_place++;
}
