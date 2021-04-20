/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:03:58 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/20 16:53:34 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	test(t_data data)
{
	//int x = 0;

	printf("pos_x = %d\n", data.pos_x);
	printf("pos_y = %d\n", data.pos_y);
	printf("ce_r = %d\n", data.ce_r);
	printf("ce_g = %d\n", data.ce_g);
	printf("ce_b = %d\n", data.ce_b);
	printf("fl_r = %d\n", data.fl_r);
	printf("fl_g = %d\n", data.fl_g);
	printf("fl_b = %d\n", data.fl_b);
	printf("NO = %s\n", data.NO);
	printf("SO = %s\n", data.SO);
	printf("WE = %s\n", data.WE);
	printf("EA = %s\n", data.EA);
	printf("sprite = %s\n", data.sprite);

	/*while (data.map[x])
	{
		ft_putstr_fd(data.map[x], 1);
		x++;
	}*/
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
	while ((get_next_line(fd, &line)) > 0)
	{
		//printf("%s\n", line);
		parsing(data, line);
	}
	check_data(data);
	test(*data);
	return (0);
}


/*
** C/F si depasse 255
** C/F si ya plusieurs ,
** random line
*/