/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/06 12:05:13 by thgillai         ###   ########.fr       */
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
		if (!line[0])
			emptylineinmap(data);
		parsing(data, line);
	}
	check_data(data);
	checkifhole(data);
	test(*data);
	window(data);
	return (0);
}
