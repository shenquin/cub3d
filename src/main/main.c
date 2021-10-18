/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/18 14:32:43 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	launch(t_data *data)
{
	get_pos(data);
	assign_pos(data);
	assigntextures(data);
	check_data(data);
	checkifhole(data);
	window(data);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_data	*data;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		exit_error("False argument");
	line = NULL;
	data = ft_calloc2(sizeof(t_data));
	if (ac != 2)
		exit_error("Invalid arguments number");
	allocmap(data, fd);
	fd = open(av[1], O_RDONLY);
	data->mlx = mlx_init();
	data->screenwidth = 1024;
	data->screenheight = 768;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!line[0])
			emptylineinmap(data);
		parsing(data, line);
	}
	launch(data);
	return (0);
}
