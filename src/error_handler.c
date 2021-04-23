/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:43:33 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/23 10:55:49 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	verifmapline(char *line)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' & line[i] != '2' && line[i] != 'N'
		&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			exit_error("invalid map");
		i++;
	}
	if (line[i - 1] != '1')
		exit_error("map error");
}

void	check_cefl(char *line)
{
	int	i;
	int	nb_str;

	i = 1;
	nb_str = 0;
	while (line[i])
	{
		if (ft_isalnum(line[i]))
			if (!ft_isalnum(line[i - 1]))
				nb_str++;
		i++;
	}
	if (nb_str != 3)
		exit_error("Invalid ceiling or floor");
	i = 1;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_ispace(line[i]) && !(line[i] == ','))
			exit_error("Invalid ceiling or floor");
		i++;
	}
}

void	check_data(t_data *data)
{
	int j;

	j = 0;
	if (data->pos_x == 0 || data->pos_y == 0)
		exit_error("Invalid resolution");
	if (data->map_argnb < 8)
		exit_error("too few arguments in .cub file");
	if (data->fl_r > 255 || data->fl_g > 255 || data->fl_b > 255)
		exit_error("Invalid floor");
	if (data->ce_r > 255 || data->ce_g > 255 || data->ce_b > 255)
		exit_error("Invalid ceiling");
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1')
			exit_error("invalid map");
		j++;
	}
	j = 0;
	while (data->map[data->nb_line - 1][j])
	{
		if (data->map[data->nb_line - 1][j] != '1')
			exit_error("invalid map");
		j++;
	}
}

void	check_comma(char *line)
{
	int	i;
	int	nb_comma;

	i = 0;
	nb_comma = 0;
	while (line[i])
		if (line[i++] == ',')
			nb_comma++;
	if (nb_comma != 2)
		exit_error("invalid ceiling or floor");
}

void	exit_error(char *error_string)
{
	ft_putstr_fd(error_string, 1);
	ft_putstr_fd(", cub3d can't launch.\n", 1);
	exit(0);
}
