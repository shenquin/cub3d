/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/19 20:12:23 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	checkav(char *av)
{
	int	i;

	i = (ft_strlen(av) - 4);
	if (av[i] == '.' && av[i + 1] == 'c'
		&& av[i + 2] == 'u' && av[i + 3] == 'b')
		return ;
	else
		exit_error("Wrong map format");
}

void	launch(t_data *data)
{
	get_pos(data);
	assign_pos(data);
	assigntextures(data);
	check_data(data);
	checkifhole(data);
	window(data);
}

void	goparse(int fd, char *line, t_data *data)
{
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!line[0])
			emptylineinmap(data);
		else if (data->mapfinished == 1)
			exit_error("Empty line in map");
		parsing(data, line);
		free(line);
	}
	if (!line[0])
		emptylineinmap(data);
	else if (data->mapfinished == 1)
		exit_error("Empty line in map");
	parsing(data, line);
	free(line);
	if (data->nb_line == 0)
		exit_error("No content");
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_data	*data;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		exit_error("False argument");
	checkav(av[1]);
	line = NULL;
	data = ft_calloc2(sizeof(t_data));
	if (ac != 2)
		exit_error("Invalid arguments number");
	allocmap(data, fd);
	fd = open(av[1], O_RDONLY);
	data->mlx = mlx_init();
	data->screenwidth = 1024;
	data->screenheight = 768;
	goparse(fd, line, data);
	launch(data);
	return (0);
}
