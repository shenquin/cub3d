/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:19 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/18 14:32:23 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	hexa_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	fl(char *line, t_data *data)
{
	int	i;

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
	data->color_fl = hexa_color(data->fl_r, data->fl_g, data->fl_b);
	data->map_argnb += 1;
}

void	ce(char *line, t_data *data)
{
	int	i;

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
	data->color_ce = hexa_color(data->ce_r, data->ce_g, data->ce_b);
	data->map_argnb += 1;
}
