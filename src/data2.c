/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:32:09 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/16 16:57:11 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	north(char *line, t_data *data)
{
	data->NO = ft_strtrim(line, " ");
	data->map_argnb += 1;
}

void	south(char *line, t_data *data)
{
	data->SO = ft_strtrim(line, " ");
	data->map_argnb += 1;
}

void	west(char *line, t_data *data)
{
	data->WE = ft_strtrim(line, " ");
	data->map_argnb += 1;
}

void	east(char *line, t_data *data)
{
	data->EA = ft_strtrim(line, " ");
	data->map_argnb += 1;
}

void	sprite(char *line, t_data *data)
{
	data->sprite = ft_strtrim(line, " ");
	data->map_argnb += 1;
}
