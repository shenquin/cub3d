/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/23 10:58:21 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	test(t_data data)
{
	// int x = 0;

	printf("R %d %d\n\n", data.pos_x, data.pos_y);
	printf("NO %s\n", data.NO);
	printf("SO %s\n", data.SO);
	printf("WE %s\n", data.WE);
	printf("EA %s\n\n", data.EA);
	printf("S %s\n", data.sprite);
	printf("C %d,%d,%d\n", data.ce_r, data.ce_g, data.ce_b);
	printf("F %d,%d,%d\n\n", data.fl_r,data.fl_g,data.fl_b);

	for (int i = 0; i < data.nb_line; i++)
	{
		printf("%s", data.map[i]);
		printf("\n");
	}
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
	allocmap(data, fd);
	fd = open(av[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		parsing(data, line);
	}
	check_data(data);
	test(*data);
	return (0);
}
