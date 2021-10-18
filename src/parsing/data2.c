/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:32:09 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/18 10:27:37 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	north(char *line, t_data *data)
{
	data->no = ft_strtrim(line, " ");
	data->imgno = mlx_xpm_file_to_image(data->mlx, data->no,
			&data->texwidth, &data->texheight);
	if (data->imgno == NULL)
		exit_error("Invalid NO path");
	data->map_argnb += 1;
}

void	south(char *line, t_data *data)
{
	data->so = ft_strtrim(line, " ");
	data->imgso = mlx_xpm_file_to_image(data->mlx, data->so,
			&data->texwidth, &data->texheight);
	if (data->imgso == NULL)
		exit_error("Invalid SO path");
	data->map_argnb += 1;
}

void	west(char *line, t_data *data)
{
	data->we = ft_strtrim(line, " ");
	data->imgwe = mlx_xpm_file_to_image(data->mlx, data->we,
			&data->texwidth, &data->texheight);
	if (data->imgwe == NULL)
		exit_error("Invalid WE path");
	data->map_argnb += 1;
}

void	east(char *line, t_data *data)
{
	data->ea = ft_strtrim(line, " ");
	data->imgea = mlx_xpm_file_to_image(data->mlx, data->ea,
			&data->texwidth, &data->texheight);
	if (data->imgea == NULL)
		exit_error("Invalid EA path");
	data->map_argnb += 1;
}
