/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/16 12:01:51 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ext_verif(char *av)
{
	int i;
	int j;
	char *ext;

	j = 0;
	i = ft_strlen(av);
	ext = malloc(sizeof(char) * 4);
	if (!ext)
		exit_error("Malloc failed");
	while (j < 4)
		ext[j++] = av [--i];
	if (ft_strncmp(ext, "buc.", 1) != 0)
		exit_error("Wrong map extension");
}

void	test(t_data data)
{
	printf("\nNO %s\n", data.NO);
	printf("SO %s\n", data.SO);
	printf("WE %s\n", data.WE);
	printf("EA %s\n\n", data.EA);
	printf("C %d,%d,%d\n", data.ce_r, data.ce_g, data.ce_b);
	printf("F %d,%d,%d\n\n", data.fl_r,data.fl_g,data.fl_b);

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
	ext_verif(av[1]);
	while ((get_next_line(fd, &line)) > 0)
	{
		parsing(data, line);
	}
	check_data(data);
	test(*data);
	return (0);
}
