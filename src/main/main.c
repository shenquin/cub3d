/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/13 13:17:40 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	test(t_data data)
{
	printf("\nNO %s\n", data.no);
	printf("SO %s\n", data.so);
	printf("WE %s\n", data.we);
	printf("EA %s\n\n", data.ea);
	printf("C %d,%d,%d\n", data.ce_r, data.ce_g, data.ce_b);
	printf("F %d,%d,%d\n\n", data.fl_r, data.fl_g, data.fl_b);
	for (int i = 0; i < data.nb_line; i++)
	{
		printf("%s", data.map[i]);
		printf("\n");
	}
	printf("\nPosition = %c\n\n", data.position);
}

void	checkav(char *av)
{
	int i;

	i = (ft_strlen(av) - 4);
	if (av[i] == '.' && av[i + 1] == 'c'
		&& av[i + 2] == 'u' && av[i + 3] == 'b')
		return ;
	else
		exit_error("Wrong map format");
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_data	*data;

	fd = open(av[1], O_RDONLY);
	line = NULL;
	data = ft_calloc2(sizeof(t_data));
	if (ac != 2)
		exit_error("Invalid arguments number");
	checkav(av[1]);
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
	get_pos(data);
	assign_pos(data);
	assigntextures(data);
	check_data(data);
	checkifhole(data);
	test(*data);
	window(data);
	return (0);
}
