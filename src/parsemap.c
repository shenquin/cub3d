/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:35:41 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/22 16:39:38 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	allocmap(t_data *data, int fd)
{
	int i;
	char *line2;

	i = 0;
	line2 = NULL;
	while (get_next_line(fd, &line2) > 0)
		if (line2[0] == '1')
			data->nb_line++;
	data->map = malloc(sizeof(char*) * data->nb_line);
	if (!data->map)
		exit_error("fail with memory allocation");
}

void	parsemap(char *line, t_data *data)
{
	int j;

	j = 0;
	data->map[data->line_place] = ft_strdup(line);
	data->line_place++;
}
