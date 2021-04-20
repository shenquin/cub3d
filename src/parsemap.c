/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:35:41 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 14:10:22 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
void	allocmap(char *line, t_data *data)
{
	t_utils	*utils;

	utils = ft_calloc2(sizeof(t_utils));
	data->map[utils->i] = malloc(sizeof(char *) * ft_strlen(line));
	printf ("debug1\n");
	printf ("debug2\n");
	parsemap(line, data, utils);
}

void	parsemap(char *line, t_data *data, t_utils *utils)
{
	int	j;

	j = 0;
	utils = ft_calloc2(sizeof(t_utils));
	//data->map[utils->i];
	while (line[j])
	{
		data->map[utils->i][j] = line[j];
		printf("i = %d j = %d\n", utils->i, j);
		j++;
	}
	utils->i++;
}
