/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:19 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/16 11:26:45 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	data->map_argnb += 1;
}
