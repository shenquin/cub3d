/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:19:53 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/14 13:58:52 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	fl(char *line, t_data *data)
{
	int i;

	i = 0;
	data->fl_r = ft_atoi(line);
	while (ft_ispace(line[i]))
		i++;
	while (ft_isalnum(line[i]))
		i++;
	i++;
	data->fl_g = ft_atoi(&line[i]);
	while (ft_isalnum(line[i]))
		i++;
	i++;
	data->fl_b = ft_atoi(&line[i]);
}

void	ce(char *line, t_data *data)
{
	int i;

	i = 0;
	data->ce_r = ft_atoi(line);
	while (ft_ispace(line[i]))
		i++;
	while (ft_isalnum(line[i]))
		i++;
	i++;
	data->ce_g = ft_atoi(&line[i]);
	while (ft_isalnum(line[i]))
		i++;
	i++;
	data->ce_b = ft_atoi(&line[i]);
}

void	res(char *line, t_data *data)
{
	int i;
	int max_x;
	int max_y;

	i = 0;
	data->pos_x = ft_atoi(line);
	while (ft_ispace(line[i]))
		i++;
	while (ft_isalnum(line[i]))
		i++;
	data->pos_y = ft_atoi(&line[i]);
	mlx_get_screen_size(data->mlx_ptr, &max_x, &max_y);
	if (data->pos_x > max_x)
		data->pos_x = max_x;
	if (data->pos_y > max_y)
		data->pos_y = max_y;
}

void	parsing(t_data *data, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		res(&line[1], data);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		north(&line[2], data);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		south(&line[2], data);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		west(&line[2], data);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		east(&line[2], data);
	else if (line[0] == 'S' && line[1] == ' ')
		sprite(&line[1], data);
	else if (line[0] == 'C' && line[1] == ' ')
		ce(&line[1], data);
	else if (line[0] == 'F' && line[1] == ' ')
		fl(&line[1], data);
	else if (line[0] == 0)
		return ;
	/*else
		exit_error("Parsing data error");*/
}

//mlx_xpm_file_to_image <-- regarde si string invalide