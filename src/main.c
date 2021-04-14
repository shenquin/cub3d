/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/14 14:01:07 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	test(t_data data)
{
	printf("pos_x = %d\n", data.pos_x);
	printf("pos_y = %d\n", data.pos_y);
	printf("fl_r = %d\n", data.fl_r);
	printf("fl_g = %d\n", data.fl_g);
	printf("fl_b = %d\n", data.fl_b);
	printf("ce_r = %d\n", data.ce_r);
	printf("ce_g = %d\n", data.ce_g);
	printf("ce_b = %d\n", data.ce_b);
	printf("NO = %s\n", data.NO);
	printf("SO = %s\n", data.SO);
	printf("WE = %s\n", data.WE);
	printf("EA = %s\n", data.EA);
	printf("sprite = %s\n", data.sprite);
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
		exit_error("Wrong arg number");
	while ((get_next_line(fd, &line)) > 0)
	{
		parsing(data, line);
	}
	test(*data);
	return (0);
}
