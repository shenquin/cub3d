/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:45 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/18 10:27:46 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	assigntextures(t_data *data)
{
	data->addrno = (int *)mlx_get_data_addr(data->imgno, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->addrso = (int *)mlx_get_data_addr(data->imgso, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->addrwe = (int *)mlx_get_data_addr(data->imgwe, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->addrea = (int *)mlx_get_data_addr(data->imgea, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
