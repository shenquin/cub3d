/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:19 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/16 16:57:00 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	screen(t_data *data)
{
	int max_x;
	int max_y;

	mlx_get_screen_size(data->mlx_ptr, &max_x, &max_y);
	if (data->pos_x > (unsigned int)max_x || data->pos_x > INT_MAX)
		data->pos_x = max_x;
	if (data->pos_y > (unsigned int)max_y || data->pos_y > INT_MAX)
		data->pos_y = max_y;
}

void	fl(char *line, t_data *data)
{
	int i;

	i = 0;
	check_cefl(&line[i]);
	data->fl_r = ft_atoi(line);
	while (ft_isdigit(line[i]) || ft_ispace(line[i]))
		i++;
	i++;
	data->fl_g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) || ft_ispace(line[i]))
		i++;
	i++;
	data->fl_b = ft_atoi(&line[i]);
	data->map_argnb += 1;
}

void	ce(char *line, t_data *data)
{
	int i;

	i = 0;
	check_cefl(&line[i]);
	data->ce_r = ft_atoi(line);
	while (ft_isdigit(line[i]) || ft_ispace(line[i]))
		i++;
	i++;
	data->ce_g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) || ft_ispace(line[i]))
		i++;
	i++;
	data->ce_b = ft_atoi(&line[i]);
	data->map_argnb += 1;
}

void	res(char *line, t_data *data)
{
	int i;

	i = 0;
	data->pos_x = ft_atoi2(line);
	while (ft_ispace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		i++;
	data->pos_y = ft_atoi2(&line[i]);
	while (ft_ispace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i])
	{
		if (!ft_ispace(line[i]))
			exit_error("Invalid resolution");
		i++;
	}
	screen(data);
	data->map_argnb += 1;
}
